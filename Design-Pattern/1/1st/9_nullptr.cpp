//C 언어에서 0은 int타입이지만, 컴파일러에 의해서 특별하게 처리 됩니다.

int main()
{
    // int *p = 10; //error!
    //int *p = 0; //0은 정수이지만 포인터로 암묵적 형변환이 된다.

    int *p = nullptr; //권장
    //int a = nullptr; //error!

    //bool b = nullptr; //error!
    bool b(nullptr); // 직점 초기화시 nullptr을 bool의 암묵적 변환이 허용됩니다.
}

//C++11에서는 포인터 0을 나타내는 nullptr를 제공