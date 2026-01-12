#include "PauseMenuWidget.h"
#include "GameFramework/PlayerController.h"

void UPauseMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (ResumeButton)
    {
        ResumeButton->OnClicked.AddDynamic(this, &UPauseMenuWidget::OnResumeClicked);
        ApplyStyledButton(ResumeButton);
        ResumeButton->SetKeyboardFocus();
    }

    if (ExitButton)
    {
        ExitButton->OnClicked.AddDynamic(this, &UPauseMenuWidget::OnExitClicked);
        ApplyStyledButton(ExitButton);
    }

    // Preserve existing pause behavior
    if (APlayerController* PC = GetOwningPlayer())
    {
        PC->SetInputMode(FInputModeUIOnly());
        PC->bShowMouseCursor = true;
    }
}

void UPauseMenuWidget::OnResumeClicked()
{
    if (APlayerController* PC = GetOwningPlayer())
    {
        PC->SetPause(false);
        PC->SetInputMode(FInputModeGameOnly());
        PC->bShowMouseCursor = false;
    }

    RemoveFromParent();
}

void UPauseMenuWidget::OnExitClicked()
{
    // THIS is why it worked for you before
    if (APlayerController* PC = GetOwningPlayer())
    {
        PC->ConsoleCommand(TEXT("quit"));
    }
}
