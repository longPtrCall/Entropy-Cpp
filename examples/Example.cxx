/*
 * File: Example.cxx
 * Description: Entropy library example.
 *
 * Created: 13/05/2023 by longPtrCall.
 * Last modified: 13/05/2023 by longPtrCall.
 *
 * Copyright: 2023, longPtrCall.
 * License: Apache License, version 2.0.
 *
 *
 * - - - This file is a part of Entropy project - - -
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 *-you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 *-distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 *-limitations under the License.
 */

// Library imports.
#include <entropy/Entropy.hxx>
using namespace entropy;

// System imports.
#include <string>
#include <vector>
#include <cstdint>
#include <iostream>
using namespace std;


/*
 * @Function - entry point.
 * @Returns execution code (zero on success).
 *
 * Compile: clang++ -I../include -L../<System>/ -lentropy -o Example Example.cxx
 */
int main(void) {

    // Get entropy version data.
    cout << "Entropy version information: " << GetVersionInfo() << endl;
    cout << "Where version code is: " << GetVersionCode() << endl;

    // Encode string.
    string message = "Hello, world!";
    cout << "Message to encode: " << message << endl;

    vector<uint8_t> encoded = Encode(vector<uint8_t>(message.begin(), message.end()));
    string encoded_string = string(encoded.begin(), encoded.end());

    cout << "Encoded message: " << encoded_string << endl;

    // Decode.
    vector<uint8_t> decoded = Decode(encoded);
    string decoded_string = string(decoded.begin(), decoded.end());
    cout << "Decoded message: " << decoded_string << endl;

    // Debug info.
    uint32_t error = GetLastError();
    cout << "Last error was " << error << " (" << GetErrorString(error) << ")" << endl;
    cout << "Error message is: " << GetErrorMessage() << endl;
    return 0;
}
