#include "sound-effect.hpp"

void SoundEffect::setSound(const char* filepath, float volume) {
    buffer.loadFromFile(filepath);
    sound.setBuffer(buffer);
    sound.setVolume(volume);
}

void SoundEffect::play() {
    sound.play();
}