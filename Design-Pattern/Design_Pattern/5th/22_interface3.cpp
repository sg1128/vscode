#include <iostream>
using namespace std;

// 1. 자동차에 카메라를 연결하기 위해 지켜야 하는 규칙을 먼저 연결
// => 인터페이스

class BlackBoxCamera
{
public:
    virtual ~BlackBoxCamera() {}
    virtual void StartRecord() = 0;
    virtual void StopRecord() = 0;
};

// 2. BlackBoxCamera를 이용하
class Car
{
private:
    BlackBoxCamera *pCamera;

public:
    Car(BlackBoxCamera *p) : pCamera(p)
    {
    }

    void Start()
    {
        pCamera->StartRecord();
    }

    void Stop()
    {
        pCamera->StopRecord();
    }
};

// 3. 카메라의 작성자는 반드시 BlackBoxCamera 인터페이스를 구현해야 한다
// => BlackBoxCamera를 상속 받아서 만들어야 한다.
class Camera : public BlackBoxCamera
{
public:
    void StartRecord() override
    {
        cout << "Start Record" << endl;
    }

    void StopRecord() override
    {
        cout << "Stop Record" << endl;
    }
};

class HDCamera : public BlackBoxCamera
{
public:
    void StartRecord() override
    {
        cout << "[HD]Start Record" << endl;
    }

    void StopRecord() override
    {
        cout << "[HD]Stop Record" << endl;
    }
};

int main()
{
    Camera cam;
    Car car(&cam);

    car.Start();
    car.Stop();

    HDCamera cam1;
    Car car1(&cam1);

    car1.Start();
    car1.Stop();
    //tlfghk?sc
}