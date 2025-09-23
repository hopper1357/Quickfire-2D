#ifndef AUDIO_H
#define AUDIO_H

#include "raylib.h"

// Enum for different sound effects
typedef enum {
    SOUND_EFFECT_ATTACK,
    // Add more sound effects here
    MAX_SOUND_EFFECTS
} SoundEffect;

// Enum for different music tracks
typedef enum {
    MUSIC_TRACK_BACKGROUND,
    // Add more music tracks here
    MAX_MUSIC_TRACKS
} MusicTrack;

void Audio_Init(void);
void Audio_Close(void);

void Audio_LoadSound(SoundEffect sound, const char* fileName);
void Audio_LoadMusic(MusicTrack music, const char* fileName);

void Audio_PlaySound(SoundEffect sound);
void Audio_PlayMusic(MusicTrack music);
void Audio_UpdateMusic(void); // Needed for music streaming

void Audio_SetMasterVolume(float volume);

#endif // AUDIO_H
