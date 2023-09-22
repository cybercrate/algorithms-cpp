#include "test_helpers/general.h"

#include <algorithms/ciphers/xor_cipher.h>
#include <gtest/gtest.h>

const auto key{7};

TEST(algorithms_cipher, xor_cipher_encrypt) {
    auto text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
                "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";

    auto expected = "Khubj'nwtrj'chkhu'tns'fjbs+'dhitbdsbsru'fcnwntdni`'bkns+'tbc'ch'bnrtjhc'sbjwhu"
                    "'nidncncris'rs'kfehub'bs'chkhub'jf`if'fknvrf)";

    EXPECT_EQ(std::string{expected}, wingmann::algorithms::ciphers::xor_cipher::encrypt(text, key));
}

TEST(algorithms_cipher, xor_cipher_decrypt) {
    auto text = "Khubj'nwtrj'chkhu'tns'fjbs+'dhitbdsbsru'fcnwntdni`'bkns+'tbc'ch'bnrtjhc'sbjwhu"
                "'nidncncris'rs'kfehub'bs'chkhub'jf`if'fknvrf)";

    auto expected = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
                    "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";

    EXPECT_EQ(std::string{expected}, wingmann::algorithms::ciphers::xor_cipher::encrypt(text, key));
}
