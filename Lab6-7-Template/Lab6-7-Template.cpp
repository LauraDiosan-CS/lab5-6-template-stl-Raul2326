#include <iostream>
#include "UI.h"
#include "Tests.h"
#include "RepoFile.h"
  

int main()
{
    TestBill();
    TestProduct();
    TestRepo();
    TestService();
    TestServiceM();
    //TestRepoFileP();
    //TestRepoFileM();
    RepoFileP P("ProductsIn.txt", "ProductsOut.txt");
    RepoFileM M("MoneyIn.txt", "MoneyOut.txt");
    Service S(P, M);
    UI UI(S);
    UI.Run();
    return 0;
}
