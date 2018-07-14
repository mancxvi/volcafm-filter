/* Copyright (c) 2018 William Oberndorfer
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

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