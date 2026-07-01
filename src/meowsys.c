// src/meowsys.c – MeowSystem DLL for Lynx
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

// ─── LIST DIRECTORY ──────────────────────────────────────────────
__declspec(dllexport) char* prowl(const char* path) {
    static char result[4096];
    result[0] = '\0';
    
    DIR* dir = opendir(path);
    if (!dir) return result;
    
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        strcat(result, entry->d_name);
        strcat(result, "\n");
    }
    closedir(dir);
    return result;
}

// ─── GET ENVIRONMENT VARIABLE ────────────────────────────────────
__declspec(dllexport) char* sniff(const char* name) {
    return getenv(name);
}

// ─── SYSTEM COMMAND ──────────────────────────────────────────────
__declspec(dllexport) int hiss(const char* cmd) {
    return system(cmd);
}

// ─── CHANGE DIRECTORY ────────────────────────────────────────────
__declspec(dllexport) int pad(const char* path) {
    return chdir(path);
}

// ─── CREATE DIRECTORY ────────────────────────────────────────────
__declspec(dllexport) int scratch(const char* path) {
    #ifdef _WIN32
        return _mkdir(path);
    #else
        return mkdir(path, 0777);
    #endif
}

// ─── REMOVE FILE ──────────────────────────────────────────────────
__declspec(dllexport) int claw(const char* path) {
    return remove(path);
}

// ─── RENAME FILE ──────────────────────────────────────────────────
__declspec(dllexport) int bat(const char* old, const char* new) {
    return rename(old, new);
}

// ─── GET CURRENT WORKING DIRECTORY ──────────────────────────────
__declspec(dllexport) char* tail() {
    static char buffer[1024];
    return getcwd(buffer, sizeof(buffer));
}

// ─── FILE EXISTS ──────────────────────────────────────────────────
__declspec(dllexport) int whisker(const char* path) {
    struct stat st;
    return stat(path, &st) == 0;
}

// ─── SLEEP ────────────────────────────────────────────────────────
__declspec(dllexport) void nap(int seconds) {
    #ifdef _WIN32
        Sleep(seconds * 1000);
    #else
        sleep(seconds);
    #endif
}