#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;

class SparseMatrix
{
public:
    SparseMatrix() {}

    void add_pincode(const string &merchant, const string &pincode)
    {
        if (matrix.find(pincode) != matrix.end())
        {
            matrix[pincode].insert(merchant);
        }
        else
        {
            matrix[pincode] = {merchant};
        }
    }

    bool check_pincode(const string &merchant, const string &pincode)
    {
        return (matrix.find(pincode) != matrix.end()) && (matrix[pincode].find(merchant) != matrix[pincode].end());
    }

    void remove_pincode(const string &merchant, const string &pincode)
    {
        assert(check_pincode(merchant, pincode) && "No such pincode exists for the merchant");
        matrix[pincode].erase(merchant);
    }

private:
    unordered_map<string, unordered_set<string>> matrix;
};

int main()
{
    SparseMatrix sparseMatrix;

    // Example usage
    sparseMatrix.add_pincode("Merchant1", "12345");
    sparseMatrix.add_pincode("Merchant2", "67890");

    bool isPincodeValid1 = sparseMatrix.check_pincode("Merchant1", "12345"); // Should be true
    bool isPincodeValid2 = sparseMatrix.check_pincode("Merchant2", "54321"); // Should be false

    cout << "Is Pincode valid for Merchant1? " << boolalpha << isPincodeValid1 << endl;
    cout << "Is Pincode valid for Merchant2? " << boolalpha << isPincodeValid2 << endl;

    sparseMatrix.remove_pincode("Merchant1", "12345");

    bool isPincodeValid3 = sparseMatrix.check_pincode("Merchant1", "12345"); // Should be false

    cout << "Is Pincode valid for Merchant1 after removal? " << boolalpha << isPincodeValid3 << endl;

    return 0;
}
