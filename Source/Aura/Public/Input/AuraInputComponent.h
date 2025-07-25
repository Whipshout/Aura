// Copyright Whipshout

#pragma once

#include "CoreMinimal.h"
#include "AuraInputConfig.h"
#include "EnhancedInputComponent.h"
#include "AuraInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template <class UserClass, typename PressedFuncType, typename ReleaseFuncType, typename HeldFuncType>
	void BindAbilityActions(const UAuraInputConfig* InputConfig, UserClass* Object, PressedFuncType PressedFunc,
	                        ReleaseFuncType ReleaseFunc, HeldFuncType HeldFunc);
};

template <class UserClass, typename PressedFuncType, typename ReleaseFuncType, typename HeldFuncType>
void UAuraInputComponent::BindAbilityActions(const UAuraInputConfig* InputConfig, UserClass* Object,
                                             PressedFuncType PressedFunc, ReleaseFuncType ReleaseFunc,
                                             HeldFuncType HeldFunc)
{
	check(InputConfig);

	for (const auto& [InputAction, InputTag] : InputConfig->AbilityInputActions)
	{
		if (InputAction && InputTag.IsValid())
		{
			if (PressedFunc)
			{
				BindAction(InputAction, ETriggerEvent::Started, Object, PressedFunc, InputTag);
			}
			if (ReleaseFunc)
			{
				BindAction(InputAction, ETriggerEvent::Completed, Object, ReleaseFunc, InputTag);
			}
			if (HeldFunc)
			{
				BindAction(InputAction, ETriggerEvent::Triggered, Object, HeldFunc, InputTag);
			}
		}
	}
}
