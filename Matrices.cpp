#include <iostream>

class D_Matrices
{
private:
    int* A;
    int n;
public:
    explicit D_Matrices(int n)
    {
        this->n = n;
        A = new int[n];
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    ~D_Matrices() { delete[]A; }
};

class LT_Matrices
{
private:
    int* A;
    int n;
public:
    explicit LT_Matrices(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    void LT_Set(int i, int j, int x);
    int LT_Get(int i, int j);
    void LT_Display();
    ~LT_Matrices() { delete[]A; }
};

class UT_Matrices
{
private:
    int* A;
    int n;
public:
    explicit UT_Matrices(int n)
    {
        this->n = n;
        A = new int[n * (n + 1) / 2];
    }
    void UT_Set(int i, int j, int x);
    int UT_Get(int i, int j);
    void UT_Display();
    ~UT_Matrices() { delete[]A; }
};

void LT_Matrices::LT_Set(int i, int j, int x)
{
    if (i >= j)
        A[n * (n - 1) / 2 + (j - 1)] = x;
}

int LT_Matrices::LT_Get(int i, int j)
{
    if (i >= j)
        return A[n * (n - 1) / 2 + (j - 1)];
    else
        return 0;
}

void LT_Matrices::LT_Display()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i >= j)
                std::cout << A[n * (n - 1) / 2 + (j - 1)] << ' ';
            else
                std::cout << 0 << ' ';
        }
        std::cout << '\n';
    }
}

void UT_Matrices::UT_Set(int i, int j, int x)
{
    if (i <= j)
        A[j * (j - 1) / 2 + (i - 1)] = x;
}

int UT_Matrices::UT_Get(int i, int j)
{
    if (i <= j)
        return A[j * (j - 1) / 2 + (i - 1)];
    else
        return 0;
}

void UT_Matrices::UT_Display()
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i <= j)
                std::cout << A[j * (j - 1) / 2 + (i - 1)] << ' ';
            else
                std::cout << 0 << ' ';
        }
        std::cout << '\n';
    }
}

void D_Matrices::Set(int i, int j, int x)
{
    if (i == j)
        A[i - 1] = x;
}

int D_Matrices::Get(int i, int j)
{
    if (i == j)
        return A[i - 1];
    else
        return 0;
}

void D_Matrices::Display()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                std::cout << A[i] << ' ';
            else
                std::cout << 0 << ' ';
        }
        std::cout << '\n';
    }
}



int main()
{
    auto o = new UT_Matrices(5);
    int x;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (i <= j) {
                std::cin >> x;
                o->UT_Set(i, j, x);
            }
        }
    }
    o->UT_Display();
    std::cout << o->UT_Get(2, 3);
    delete o;
}

/*
 std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dist(1, 9);


struct term
{
	int ceoff;
	int Exp;
};

struct polynominal
{
	int n;
	struct term* t;
};

int main()
{
	struct polynominal P;
	P.n = 5;
	P.t = new term[P.n];
	for (int i = 0; i < 5; i++) {
		P.t[i].ceoff = dist(gen);
		P.t[i].Exp = dist(gen);
	}
	int x = 5, Px = 0;
	for (int i = 0; i < 5; i++) {
		Px += P.t[i].ceoff * pow(x, P.t[i].Exp);
	}
	struct polynominal T;
	T.n = 9;
	T.t = new term[T.n];
	for (int i = 0; i < 9; i++) {
		T.t[i].ceoff = dist(gen);
		T.t[i].Exp = dist(gen);
	}
	int Tx = 0;
	for (int i = 0; i < 9; i++) {
		Tx += T.t[i].ceoff * pow(x, T.t[i].Exp);
	}
	std::cout << Px + Tx << std::endl;
	delete[] P.t;
	delete[] T.t;
}
*/
