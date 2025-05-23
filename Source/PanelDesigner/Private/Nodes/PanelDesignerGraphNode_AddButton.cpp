﻿#include "Nodes/PanelDesignerGraphNode_AddButton.h"



// Might add in later if I wanna support other languages. Just so I don't forget 🤗💕
//#define LOCTEXT_NAMESPACE "PanelDesignerGraphNode_AddButton"

UPanelDesignerGraphNode_AddButton::UPanelDesignerGraphNode_AddButton()
{
    ButtonLabel = TEXT("New Button");
}

FText UPanelDesignerGraphNode_AddButton::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
    return FText::FromString(FString::Printf(TEXT("Add Button: %s"), *ButtonLabel));
}

//#undef LOCTEXT_NAMESPACE
