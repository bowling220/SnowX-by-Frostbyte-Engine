#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "PauseMenuWidget.generated.h"

UCLASS()
class SNOWX_API UPauseMenuWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

    // Bound buttons (names MUST match UMG)
    UPROPERTY(meta = (BindWidget))
    UButton* ResumeButton;

    UPROPERTY(meta = (BindWidget))
    UButton* ExitButton;

    UFUNCTION()
    void OnResumeClicked();

    UFUNCTION()
    void OnExitClicked();

private:
    void ApplyStyledButton(UButton* Button);
};
