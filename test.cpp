#include <UnitTest++/UnitTest++.h>
#include <../kurs/ham8.cpp>

struct Hamming8_fixture {
    Hamming8 * object;
    Hamming8_fixture()
    {
        object = new Hamming8();
    }
    ~Hamming8_fixture()
    {
        delete object;
    }
};

SUITE(EncodeTest)
{
    TEST_FIXTURE(Hamming8_fixture, CorrectData) {
        object->encode("BO0M!");
        CHECK(true);
    }
    TEST_FIXTURE(Hamming8_fixture, EmptyString) {
        CHECK_THROW(object->encode(""), error_hamming);
    }
    TEST_FIXTURE(Hamming8_fixture, InvalidCharacter) {
        CHECK_THROW(object->encode("ЫжЙ"), error_hamming);
    }
}


SUITE(DecodeTest)
{
    vector<int>
    vec1 {0,1,0,1,1,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,1,0,0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1};
    TEST_FIXTURE(Hamming8_fixture, CorrectData) {
        object->decode(vec1);
        CHECK(true);
    }
    vector<int> vec2;
    TEST_FIXTURE(Hamming8_fixture, EmptyString) {
        CHECK_THROW(object->decode(vec2), error_hamming);
    }
    vector<int> vec3{1,0,1};
    TEST_FIXTURE(Hamming8_fixture, IncorrectLength) {
        CHECK_THROW(object->decode(vec3), error_hamming);
    }
    vector<int> vec4{2,0,0,1,0,1,1,1,0,0,0,1};
    TEST_FIXTURE(Hamming8_fixture, InvalidCharacter) {
        CHECK_THROW(object->decode(vec4), error_hamming);
    }
    vector<int> vec5{0,0,0,0,0,0,0,0,0,0,0,0};
    TEST_FIXTURE(Hamming8_fixture, ZeroVector) {
        CHECK_THROW(object->decode(vec5), error_hamming);
    }

}

int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}
