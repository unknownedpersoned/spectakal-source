// "gui.c" controls graphical interfaces
#include "../gui.h"

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "libs/raylib.h"

int gui_PreventDrawing = 0;
gui_Widget gui_Widgets[GUI_MAX_WIDGET];
gui_Control gui_Controls[GUI_MAX_CONTROL];
//static int _NextWidget = -1;

void _PutButton(gui_Control control) {
	
}

void _PutSlider(gui_Control control) {
	
}

void _PutTextEntry(gui_Control control) {
	
}

void _PutText(gui_Control control) {
	
}

int gui_SpawnWidget(int ShowControlButtons, char* Title) {
	//int indx = 0;
	for (int x = 0; x <= GUI_MAX_WIDGET; x++) {
		if (gui_Widgets[x].w) {
			
			break;
		}
	}
	return 0;
	
}

void gui_AddControlToWidget(gui_Control control) {
	
}

void gui_PutDemoWindow() {
	
}

void gui_PutWidgets() {
	
}

void gui_Destroy() {
	
}
