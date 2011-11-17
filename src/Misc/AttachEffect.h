#ifndef ATTACHEFFECT_H_
#define ATTACHEFFECT_H_

#include <vector>
#include <TechnoClass.h>

#include "../Utilities/Template.h"


class AttachEffectTypeClass {
public:

	char ID[24]; // as westwood once said, 24 chars ought to be enough for any ID
	Valueable<int> Duration;
	Valueable<bool> Cumulative;
	
	//#1573, #1623 animations on units
	Valueable<AnimTypeClass *> AnimType;

	//#255, crate stat modifiers on weapons
	Valueable<double> FirepowerMultiplier;
	Valueable<double> ArmorMultiplier;
	Valueable<double> SpeedMultiplier;
	Valueable<bool> Cloakable;

	virtual void Attach(TechnoClass* Target, int Duration);

	AttachEffectTypeClass(): Cumulative(false),
		Duration(0),
		AnimType(NULL),
		FirepowerMultiplier(1),
		ArmorMultiplier(1),
		SpeedMultiplier(1),
		Cloakable(false)
		{
			this->ID[0] = 0;
		};

	void Read(INI_EX *exINI, const char * section);
};

class AttachEffectClass {
public:
	AttachEffectClass(AttachEffectTypeClass* AEType, int Timer): Type(AEType), Animation(NULL), ActualDuration(Timer) {
	}

	AttachEffectTypeClass * Type;
	AnimClass * Animation;
	int ActualDuration;

	void Destroy();

	void InvalidateAnimPointer(AnimClass *ptr);

	void KillAnim();
};

#endif