/*
 * File: __internal__.hxx
 * Description: Entropy symbols header.
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

// System imports.
#include <string>
#include <vector>
#include <cstdint>

// External symbol import.
#if defined(_MSC_VER)
#define __entropy_library_import extern "C" __declspec(dllimport)
#else
#define __entropy_library_import extern "C"
#endif

/*
 * @Function - encode data.
 * @Param _data - data to encode.
 * @Param _size - size of data.
 */
__entropy_library_import void __entropy_Encode(const uint8_t* _data, const uint32_t _size);


/*
 * @Function - decode data (with no passwords).
 * @Param _data - encoded data to decode.
 * @Param _size - data size.
 */
__entropy_library_import uint8_t* __entropy_Decode(const uint8_t* _data, const uint32_t _size);


/*
 * @Function - get output pointer.
 * @Returns pointer to output array.
 */
__entropy_library_import uint8_t* __entropy_GetLastOutput(void);


/*
 * @Function - get output size.
 * @Returns size of last output.
 */
__entropy_library_import uint32_t __entropy_GetLastOutputSize(void);


/*
 * @Function - delete output.
 */
__entropy_library_import void __entropy_Finalize(void);


/*
 * @Function - get last error code.
 * @Returns last library error.
 */
__entropy_library_import uint32_t __entropy_GetLastError(void);


/*
 * @Function - get error description.
 * @Param _error - requested error description.
 * @Returns verbose description or empty string if error does not exists.
 */
__entropy_library_import std::string __entropy_GetErrorString(const uint32_t _error);


/*
 * @Function - get error message.
 * @Returns (possibly) a reason for the last error caught.
 */
__entropy_library_import std::string __entropy_GetErrorMessage(void);


/*
 * @Function - get version info.
 * @Returns entropy version
 */
__entropy_library_import std::string __entropy_GetVersionInfo(void);


/*
 * @Function - get version code.
 * @Returns library version info as a long number.
 */
__entropy_library_import uint64_t __entropy_GetVersionCode(void);
