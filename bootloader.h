/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _RECOVERY_BOOTLOADER_H
#define _RECOVERY_BOOTLOADER_H

static const int BOOTLOADER_MESSAGE_OFFSET_IN_MISC = 16 * 1024;

/* Bootloader Message
 *
 * This structure describes the content of a block in flash
 * that is used for recovery and the bootloader to talk to
 * each other.
 *
 * The command field is updated by linux when it wants to
 * reboot into recovery or to update radio or bootloader firmware.
 * It is also updated by the bootloader when firmware update
 * is complete (to boot into recovery for any final cleanup)
 *
 * The status field is written by the bootloader after the
 * completion of an "update-radio" or "update-hboot" command.
 *
 * The recovery field is only written by linux and used
 * for the system to send a message to recovery or the
 * other way around.
 *
 * The systemFlag field is used for the system to send a message to recovery.
 */
struct bootloader_message {
    char command[32];
    char status[32];
    char recovery[768];
    char systemFlag[256];
};

/* Read and write the bootloader command from the "misc" partition.
 * These return zero on success.
 */
int get_bootloader_message(struct bootloader_message *out);
int set_bootloader_message(const struct bootloader_message *in);

#endif
