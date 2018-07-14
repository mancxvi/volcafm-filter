#include <Arduino.h>
#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
    MIDI.begin();
}

void loop() {
    if (MIDI.read()) {
        switch (MIDI.getType()) {
        case midi::NoteOn:
        case midi::NoteOff:
            MIDI.send(midi::ControlChange, 41, MIDI.getData2(), MIDI.getChannel());
            // fall through to send note
        default:
            MIDI.send(MIDI.getType(), MIDI.getData1(), MIDI.getData2(), MIDI.getChannel());
        }
    }
}