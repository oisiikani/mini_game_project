#pragma once

//今押された
bool IsKeyPush(int Key_code);

//押し続けられている
bool IsKeyKeep(int Key_code);

//今離されたか
bool IsKeyRelease(int Key_code);

bool IsKeyDown(int Key_code);
