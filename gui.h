// "gui.h" controls graphical interfaces
#ifndef INCLUDE_GUI_H
#define INCLUDE_GUI_H

#define GUI_MAX_WIDGET 20
#define GUI_MAX_CONTROL 50

extern int gui_PreventDrawing;

typedef enum {
	gui_Button,
	gui_Slider,
	gui_TextEntry,
	gui_Text
} gui_ControlType;

typedef struct {
	int x, y;
	int w, h;
	char* Title;
	int DrawWindowButtons;
} gui_Widget;

typedef struct {
	int AssignWidget;
	gui_ControlType Type;
	int* Properties;
} gui_Control;

int gui_SpawnWidget(int ShowControlButtons, char* Title);

void gui_AddControlToWidget(gui_Control Control);

void gui_PutDemoWindow();

void gui_PutWidgets();

void gui_Destroy();

#endif
