/*
 * File: Entropy.hxx
 * Description: Entropy library header.
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
#include "__internal__.hxx"

// System imports.
#include <string>
#include <vector>
#include <cstdint>

/*
 * Module-level namespace.
 */
namespace entropy {


    /*
     * @Function - encode data.
     * @Param _data - data to encode.
     * @Returns original data encoded with NO ENCRYPTION.
     */
    inline std::vector<uint8_t> Encode(const std::vector<uint8_t>& _data) {

        __entropy_Encode(&_data[0], _data.size());
        uint8_t* pointer = __entropy_GetLastOutput();
        std::vector<uint8_t> output(pointer, pointer + __entropy_GetLastOutputSize());
        __entropy_Finalize();
        return output;
    }


    /*
     * @Function - decode data (with no passwords).
     * @Param _data - encoded data to decode.
     * @Returns a new array with decoded data.
     */
    inline std::vector<uint8_t> Decode(const std::vector<uint8_t>& _data) {

        __entropy_Decode(&_data[0], _data.size());
        uint8_t* pointer = __entropy_GetLastOutput();
        std::vector<uint8_t> output(pointer, pointer + __entropy_GetLastOutputSize());
        __entropy_Finalize();
        return output;
    }


    /*
     * @Function - get last error code.
     * @Returns last library error.
     */
    inline std::uint32_t GetLastError(void) {

        return __entropy_GetLastError();
    }


    /*
     * @Function - get error description.
     * @Param _error - requested error description.
     * @Returns verbose description or empty string if error does not exists.
     */
    inline std::string GetErrorString(const uint32_t _error) {

        return __entropy_GetErrorString(_error);
    }


    /*
     * @Function - get error message.
     * @Returns (possibly) a reason for the last error caught.
     */
    inline std::string GetErrorMessage(void) {

        return __entropy_GetErrorMessage();
    }


    /*
     * @Function - get version info.
     * @Returns entropy version
     */
    inline std::string GetVersionInfo(void) {

        return __entropy_GetVersionInfo();
    }


    /*
     * @Function - get version code.
     * @Returns library version info as a long number.
     */
    inline uint64_t GetVersionCode(void) {

        return __entropy_GetVersionCode();
    }
}
