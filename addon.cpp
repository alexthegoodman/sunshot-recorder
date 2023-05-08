#include <nan.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>

using namespace v8;
using namespace std;

HWND target_hwnd = nullptr;
LPCSTR search_title = nullptr;

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    char window_title[256];
    GetWindowText(hwnd, window_title, sizeof(window_title));
    if (strstr(window_title, search_title)) {
        target_hwnd = hwnd;
        return FALSE; // Stop enumerating windows
    }
    return TRUE;
}

NAN_METHOD(SetTargetWindow) {
    if (!info[0]->IsString()) return Nan::ThrowError("Must pass a string");
    Nan::Utf8String path(info[0]);
    search_title = *path;

    target_hwnd = nullptr;
    EnumWindows(EnumWindowsProc, 0);
    if (target_hwnd == nullptr) {
        Nan::ThrowError("Window not found.");
        return;
    }

    RECT rect;
    GetWindowRect(target_hwnd, &rect);
    int width = rect.right - rect.left;
    int height = rect.bottom - rect.top;
    int x = rect.left;
    int y = rect.top;

    // cout << "Window found at (" << x << "," << y << ") with size " << width << "x" << height << endl;
    
    string window_data = "{\"x\": " + to_string(x) + ", \"y\": " + to_string(y) + ", \"width\": " + to_string(width) + ", \"height\": " + to_string(height) + "}";
    // print window_data

    info.GetReturnValue().Set(Nan::New<String>(window_data).ToLocalChecked());
}

NAN_METHOD(Print) {
  if (!info[0]->IsString()) return Nan::ThrowError("Must pass a string");
  Nan::Utf8String path(info[0]);
  printf("Printed from C++: %s\n", *path);
}

NAN_MODULE_INIT(InitAll) {
  Nan::Set(target, Nan::New<String>("print").ToLocalChecked(), Nan::GetFunction(Nan::New<FunctionTemplate>(Print)).ToLocalChecked());
  Nan::Set(target, Nan::New<String>("setTargetWindow").ToLocalChecked(), Nan::GetFunction(Nan::New<FunctionTemplate>(SetTargetWindow)).ToLocalChecked());
}

NODE_MODULE(a_native_module, InitAll)