/// @file   xor_cipher.h
/// @author Alexander Shavrov (alexander.shavrov@outlook.com)
/// @brief  Xor cipher implementation.
/// @date   2022-10-10
///
/// @copyright Copyright (c) 2022
///
/// This file is distributed under the MIT License.
/// See LICENSE file for details.
///

#ifndef WINGMANN_ALGORITHMS_CIPHERS_XOR_CIPHER_H
#define WINGMANN_ALGORITHMS_CIPHERS_XOR_CIPHER_H

#include <sstream>

namespace wingmann::algorithms::ciphers::xor_cipher {

/// @brief Encrypt given text using XOR cipher.
///
/// @param text A text to be encrypted.
/// @param key  To be used for encryption.
/// @return     Encrypted text.
///
/// @see https://en.wikipedia.org/wiki/XOR_cipher
///
std::string encrypt(const std::string& text, const int& key)
{
    std::stringstream encrypted_text;

    for (auto& c: text) {
        auto encrypted_char = static_cast<char>(c ^ key);
        encrypted_text << encrypted_char;
    }
    return encrypted_text.str();
}

/// @brief Decrypt given text using XOR cipher.
///
/// @param text A text to be decrypted.
/// @param key  To be used for decryption.
/// @return     Decrypted text.
///
/// @see https://en.wikipedia.org/wiki/XOR_cipher
///
std::string decrypt(const std::string& text, const int& key)
{
    return encrypt(text, key);
}

} // namespace wingmann::algorithms::ciphers

#endif // WINGMANN_ALGORITHMS_CIPHERS_XOR_CIPHER_H
