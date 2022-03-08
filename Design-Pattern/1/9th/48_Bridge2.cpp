#include <iostream>
using namespace std;

//    MP3
//     |
//     *
//     |
// SmartPhone

struct MP3
{
    virtual ~MP3() {}

    virtual void Play() = 0;
    virtual void Stop() = 0;

    // virtual void PlayOneMinute() = 0;
    // 인터페이스의 문제점
    // : 새로운 요구사항의 확장이 어렵습니다.
    // => 인터페이스의 구현부(SmartPhone)와 인터페이스(MP3)를 분리해서
    //    상호 독립적인 업데이트가 가능하게 하자.
    //   : Bridge Pattern
};

class MP3Bridge
{
    MP3 *pImpl; // pointer to implementation
public:
    MP3Bridge(MP3 *p)
        : pImpl(p)
    {
    }

    void Play() { pImpl->Play(); }
    void Stop() { pImpl->Stop(); }
};

class Person
{
    MP3Bridge *mp3;

public:
    Person(MP3Bridge *p)
        : mp3(p)
    {
    }

    void PlayMusic()
    {
        mp3->Play();
        mp3->Stop();
    }
};

class SmartPhone : public MP3
{
public:
    void Play() override
    {
        cout << "SmartPhone Play Music" << endl;
    }
    void Stop() override
    {
        cout << "SmartPhone Stop Music" << endl;
    }
};

int main()
{
    SmartPhone phone;

    MP3Bridge mp3(&phone);

    Person person(&mp3);

    person.PlayMusic();
}