#include <sys/types.h>
#include <sys/socket.h>
#include <linux/if.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int sockfd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ARP) );
	if (sockfd == -1)
	{
		printf("socket error\n"); return 0;
	}

	//获取网卡信息
	sockaddr_ll addr_ll;
	memset(&addr_ll, 0, sizeof(sockaddr_ll));
	addr_ll.sll_family = PF_PACKET;

	ifreq ifr;
	strcpy(ifr.ifr_name, "ens33");
	if (ioctl(sockfd, SIOCGIFINDEX, &ifr) == -1)
	{
		printf("error ioctl SIOCGIFINDEX\n"); return 0;
	}
	addr_ll.sll_ifindex = ifr.ifr_ifindex; //接口索引


	if (ioctl(sockfd, SIOCGIFADDR, &ifr) == -1)
	{
		printf("error ioctl SIOCGIFADDR\n"); return 0;
	}
	char* ipSrc = inet_ntoa(((struct sockaddr_in*)(&(ifr.ifr_addr)))->sin_addr);
	printf("ip address : %s\n", ipSrc); //source ip

	if (ioctl(sockfd, SIOCGIFHWADDR, &ifr) == -1)
	{
		printf("error ioctl SIOCGIFHWADDR\n"); return 0;
	}
	unsigned char macSrc[ETH_ALEN];
	memcpy(macSrc, ifr.ifr_hwaddr.sa_data, ETH_ALEN); //mac address
	printf("mac address");
	for (int i = 0; i < ETH_ALEN; i++)
		printf(":%02x", macSrc[i]);
	printf("\n");

	//填充以太网首部 和 ARP信息
	unsigned char macDst[ETH_ALEN] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
	ether_header header;
	memcpy(header.ether_dhost, macDst, ETH_ALEN);
	memcpy(header.ether_shost, macSrc, ETH_ALEN);
	header.ether_type = htons(ETHERTYPE_ARP);

	ether_arp arp;
	arp.arp_hrd = htons(ARPHRD_ETHER);
	arp.arp_pro = htons(ETHERTYPE_IP);
	arp.arp_hln = ETH_ALEN;
	arp.arp_pln = 4; //IPv4
	arp.arp_op = htons(ARPOP_REQUEST);

	in_addr src_in_addr, dst_in_addr;
	inet_pton(AF_INET, ipSrc, &src_in_addr);
	inet_pton(AF_INET, "192.168.182.132", &dst_in_addr);

	memcpy(arp.arp_sha, macSrc, ETH_ALEN);
	memcpy(arp.arp_spa, &src_in_addr, 4);
	memcpy(arp.arp_tha, macDst, ETH_ALEN);
	memcpy(arp.arp_tpa, &dst_in_addr, 4);

	unsigned char sendBuf[sizeof(ether_header) + sizeof(ether_arp) ];
	memcpy(sendBuf, &header, sizeof(ether_header) );
	memcpy(sendBuf + sizeof(ether_header), &arp, sizeof(ether_arp));
	int len = sendto(sockfd, sendBuf, sizeof(sendBuf), 0, (const sockaddr*)&addr_ll, sizeof(addr_ll) );
	if (len > 0)
	{
		printf("send success\n");
	}

	return 0;
}

