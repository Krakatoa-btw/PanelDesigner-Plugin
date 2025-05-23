# 🏗 PanelDesigner Plugin Architecture 🏗

This document outlines the PanelDesigner plugin's architecture, which re-integrates AActor's Blueprint Editor to create a custom graph-based Slate/UMG UI editing system.

---

## ♻️ Editor Ownership & Lifecycle 🌊

```
─┬── PanelDesignerDefinition (UAssetDefinition)
 │ ► calls 
 └───┬── PanelDesignerBlueprintEditor (FBlueprintEditor)
     │ ► owns 
     ├───┬─ PanelDesignerBlueprintExtension (UBlueprintExtension)
     │   │ ► serializes
     │   └───── PanelDesignerGraph (UEdGraph)
     │ ► injects 
     ├───── PanelDesignerToolbar (via FExtender)
     │ ► manages 
     └──┬── PanelDesignerMode (FBlueprintEditorUnifiedMode)
        │ ► calls  
        ├───┬─ PanelDesignerTabs
            │ ► registers 
            └──┬── PanelDesignerGraph
               ├── PanelDesignerSelection
               ├── PanelDesignerVariable
               └── PanelDesignerPreview
```

---

## 📚 Class Index 📚

### 🧰 Integration

- **PanelDesignerDefinition** — Handles asset launch via UAssetDefinition
- **PanelDesignerBlueprintExtension** — Stores graph + transient UI state

### 📋 Editor & Modes

- **PanelDesignerBlueprintEditor** `FBlueprintEditor` — adds application modes.
- **PanelDesignerMode** `FBlueprintEditorUnifiedMode` — custom mode extension

### 🗂️ Toolbar & Tabs

- **PanelDesignerToolbar** — Toolbar button extension system via `FExtender`
- **PanelDesignerTabs** — Static registration logic and layout behavior

            (Individual Tabs)

- **PanelDesignerGraph** — Graph tab content (SGraphEditor-based)
- **PanelDesignerSelection** — Stack panel (Niagara-style)
- **PanelDesignerVariable** — Variables (BP-style list)
- **PanelDesignerPreview** — Live layout preview (optional)

---

## 🔌 Plugin Integration Notes 🔌

- Designed around `AActor`-derived Blueprints

- Fully non-destructive — turning off plugin reverts to Epic’s default behavior

- Tabs, toolbar, and layout registered in a modular fashion — easy to extend

- Asset-based loading ensures full editor integration without needing subsystems