//
//  ActionSubSystem.h
//

#ifndef __ActionSubSystem__
#define __ActionSubSystem__

#include "GameSubSystem.h"
#include "Core.h"
#include "Curve.h"
#include "TimeMgr.h"
#include "BoardEntity.h"
#include "RtReflectionDelegate.h"

typedef RtWeakPtr<class RealObject> RealObjectPtr;

typedef RtReflectionDelegate<Delegate1<class RealObject*> > ActionSubSystemCallback;


class ActionBase : public RtObject
{
public:
    RT_CLASS_DEFINE(ActionBase, RtObject, RtClass);
    
    ActionBase();
    virtual ~ActionBase() {}
    
    void InitWithTarget(RealObjectPtr target,float duration);
    
    virtual bool isDone() const
    {
        return true;
    }
    
    virtual void stop()
    {
        
    }
    
    virtual void step(float dt);
    
    virtual void update(float time)
    {
        
    }
    
    ActionSubSystemCallback _callback;
    RealObjectPtr          _target;
    
protected:
    
    pvztime_t   _duration;
    pvztime_t   _elapsed;
    bool        _firstTick;
};

//////////////////////////////

class ActionEntityFade : public ActionBase
{
public:
    RT_CLASS_DEFINE(ActionEntityFade, ActionBase, RtClass);
    
    ActionEntityFade() : m_bFadeOut(true) {}
    virtual ~ActionEntityFade() {}
    
    void InitWithTarget(RealObjectPtr target,float duration, bool bFadeOut = true);
    virtual bool isDone() const     override;
    virtual void update(float time) override;
    
private:
    
    bool m_bFadeOut;
    
};

//////////////////////////////

class ActionMoveTo : public ActionBase
{
public:
    RT_CLASS_DEFINE(ActionMoveTo, ActionBase, RtClass);
    
    ActionMoveTo();
    virtual ~ActionMoveTo() {}
    
    void InitWithTarget(RealObjectPtr target,float duration, const SexyVector3& position);
    
    virtual bool isDone() const     override;
    virtual void update(float time) override;
    
private:
    SexyVector3 _positionDelta;
    SexyVector3 _startPosition;
    SexyVector3 _previousPosition;
};

//////////////////////////////

typedef struct _ccBezierConfig
{
    //! end position of the bezier
    SexyVector2 endPosition;
    //! Bezier control point 1
    SexyVector2 controlPoint_1;
    //! Bezier control point 2
    SexyVector2 controlPoint_2;
} ccBezierConfig;

class ActionBezierBy : public ActionBase
{
public:
    RT_CLASS_DEFINE(ActionBezierBy, ActionBase, RtClass);
    
    ActionBezierBy() {}
    virtual ~ActionBezierBy() {}
    
    void InitWithTarget(RealObjectPtr target,
                        float duration,
                        const ccBezierConfig& c);
    
    virtual bool isDone() const     override;
    virtual void update(float time) override;
    
protected:
    ccBezierConfig      _config;
    SexyVector3         _startPosition;
    SexyVector3         _previousPosition;
};


class ActionBezierTo : public ActionBezierBy
{
public:
    RT_CLASS_DEFINE(ActionBezierTo, ActionBezierBy, RtClass);
    
    ActionBezierTo() {}
    virtual ~ActionBezierTo() {}
    
    void InitWithTarget(RealObjectPtr target,
                        float duration,
                        const ccBezierConfig& c);
    
protected:
    ccBezierConfig _toConfig;
};

//////////////////////////////

class ActionSubSystem : public GameSubSystem
{
public:
	RT_CLASS_DEFINE(ActionSubSystem, GameSubSystem, RtClass);
    virtual ~ActionSubSystem();
	
	void Update() override;
    
    void AddActionMoveTo(RealObjectPtr target,
                         float duration,
                         const SexyVector3& position,
                         ActionSubSystemCallback i_callback = ActionSubSystemCallback());
    
    void AddActionBezierBy(RealObjectPtr target,
                           float duration,
                           const ccBezierConfig& c,
                           ActionSubSystemCallback i_callback = ActionSubSystemCallback());
    
    void AddActionBezierTo(RealObjectPtr target,
                           float duration,
                           const ccBezierConfig& c,
                           ActionSubSystemCallback i_callback = ActionSubSystemCallback());
    
    void AddActionEntityFade(RealObjectPtr target,
                             float duration,
                             bool bFadeOut,
                             ActionSubSystemCallback i_callback = ActionSubSystemCallback());
    
    bool Serialize(const RtSerializeContext& i_serializeContext) override;
    
protected:
	void onInitialized() override;
	void registerForEvents() override;
	
private:
	
    std::vector<ActionBase*> m_Actions;
    std::vector<ActionBase*> m_newActions;
    
    //std::vector<RtWeakPtr<class Zombie> > m_deadZombies;
};

#endif
