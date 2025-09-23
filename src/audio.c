#include "audio.h"
#include "json.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Sound sounds[MAX_SOUND_EFFECTS];
static Music music[MAX_MUSIC_TRACKS];

void Audio_Init(void) {
    InitAudioDevice();

    // Default master volume
    float masterVolume = 1.0f;

    FILE* fp = fopen("config.json", "r");
    if (fp != NULL) {
        fseek(fp, 0, SEEK_END);
        long file_size = ftell(fp);
        fseek(fp, 0, SEEK_SET);

        char* json_string = (char*)malloc(file_size + 1);
        fread(json_string, 1, file_size, fp);
        fclose(fp);

        json_string[file_size] = '\0';

        struct json_value_s* root = json_parse(json_string, file_size);
        if (root != NULL) {
            struct json_object_s* object = json_value_as_object(root);
            if (object != NULL) {
                struct json_object_element_s* audio_settings_el = object->start;
                while(audio_settings_el != NULL) {
                    if(strcmp(audio_settings_el->name->string, "audio") == 0) {
                        struct json_object_s* audio_settings = json_value_as_object(audio_settings_el->value);
                        if (audio_settings != NULL) {
                             for (struct json_object_element_s* el = audio_settings->start; el != NULL; el = el->next) {
                                if(strcmp(el->name->string, "masterVolume") == 0) {
                                    struct json_number_s* volume_num = json_value_as_number(el->value);
                                    if(volume_num != NULL) {
                                        masterVolume = atof(volume_num->number);
                                    }
                                }
                            }
                        }
                        break;
                    }
                    audio_settings_el = audio_settings_el->next;
                }
            }
        }
        free(json_string);
        free(root);
    }

    Audio_SetMasterVolume(masterVolume);
}

void Audio_Close(void) {
    for (int i = 0; i < MAX_SOUND_EFFECTS; i++) {
        UnloadSound(sounds[i]);
    }
    for (int i = 0; i < MAX_MUSIC_TRACKS; i++) {
        UnloadMusicStream(music[i]);
    }
    CloseAudioDevice();
}

void Audio_LoadSound(SoundEffect sound, const char* fileName) {
    if (sound < MAX_SOUND_EFFECTS) {
        sounds[sound] = LoadSound(fileName);
    }
}

void Audio_LoadMusic(MusicTrack music_track, const char* fileName) {
    if (music_track < MAX_MUSIC_TRACKS) {
        music[music_track] = LoadMusicStream(fileName);
    }
}

void Audio_PlaySound(SoundEffect sound) {
    if (sound < MAX_SOUND_EFFECTS) {
        PlaySound(sounds[sound]);
    }
}

void Audio_PlayMusic(MusicTrack music_track) {
    if (music_track < MAX_MUSIC_TRACKS) {
        PlayMusicStream(music[music_track]);
    }
}

void Audio_UpdateMusic(void) {
    for (int i = 0; i < MAX_MUSIC_TRACKS; i++) {
        if (IsMusicStreamPlaying(music[i])) {
            UpdateMusicStream(music[i]);
        }
    }
}

void Audio_SetMasterVolume(float volume) {
    SetMasterVolume(volume);
}
