#include <iostream>
#include "UI.h"
#include"Tests.h"

int main()
{
    TestProduct();
    TestRepo();
    TestService();
    Repo R("ProductsIn.txt", "ProductsOut.txt");
    RepoMoney M("MoneyIn.txt", "MoneyOut.txt");
    Service S(R, M);
    UI UI(S);
    UI.Run();
    return 0;
}
