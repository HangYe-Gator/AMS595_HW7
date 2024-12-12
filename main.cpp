#include <iostream>
#include <string>


//Q1.Input number
int Q1() {
    int n;

    std::cout << "Enter a number: ";
    std::cin >> n;

    // Use a switch statement to handle different cases
    switch (n) {
        case -1:
            std::cout << "negative one" << std::endl;
            break;
        case 0:
            std::cout << "zero" << std::endl;
            break;
        case 1:
            std::cout << "positive one" << std::endl;
            break;
        default:
            break;
    }

    std::cout << "other value" << std::endl;

    return 0;
}

//Q2:Function to print the vector
void print_vector(std::vector<int> v) {
    std::cout << "[";
    bool first = true;
    for (const auto& element : v) {
        if (!first) {
            std::cout << ", ";
        }
        std::cout << element;
        first = false;
    }
    std::cout << "]" << std::endl;
}


//Q3
void Q3() {
    // Initialize the first two Fibonacci numbers
    long long a = 1;
    long long b = 2;

    // Define the maximum value
    const long long MAX_VALUE = 4000000;

    // Inform the user about the sequence being printed
    std::cout << "Fibonacci sequence up to " << MAX_VALUE << ":\n";

    // Print the first two numbers of the sequence
    std::cout << a << ", " << b;

    while (true) {
        long long next = a + b;

        if (next > MAX_VALUE) {
            break;
        }
        std::cout << ", " << next;
        a = b;
        b = next;
    }
    std::cout << std::endl;
}


//Q4.1 is prime
bool isprime(int n) {
    // Handle edge cases
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }

    // Check for factors up to sqrt(n)
    int sqrt_n = static_cast<int>(std::sqrt(n));
    for (int i = 3; i <= sqrt_n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}


//Q4.2 factorize Function
std::vector<int> factorize(int n) {
    std::vector<int> factors;
    if (n < 1) {
        // No factors for non-positive integers
        return factors;
    }

    // Find factors up to sqrt(n)
    int sqrt_n = static_cast<int>(std::sqrt(n));
    for (int i = 1; i <= sqrt_n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i) { // Avoid adding the square root twice for perfect squares
                factors.push_back(n / i);
            }
        }
    }

    // Sort the factors in ascending order
    std::sort(factors.begin(), factors.end());

    return factors;
}



//Q4.3. prime_factorize Function
std::vector<int> prime_factorize(int n) {
    std::vector<int> prime_factors;
    if (n < 2) {
        // No prime factors for numbers less than 2
        return prime_factors;
    }

    // Factor out the number of 2s
    while (n % 2 == 0) {
        prime_factors.push_back(2);
        n /= 2;
    }

    // Factor out odd numbers starting from 3
    int sqrt_n = static_cast<int>(std::sqrt(n));
    for (int i = 3; i <= sqrt_n; i += 2) {
        while (n % i == 0) {
            prime_factors.push_back(i);
            n /= i;
            sqrt_n = static_cast<int>(std::sqrt(n)); // Update sqrt(n) as n decreases
        }
    }

    // If n is a prime number greater than 2
    if (n > 2) {
        prime_factors.push_back(n);
    }

    return prime_factors;
}


void print_pascals_triangle(int n) {
    if (n <= 0) {
        std::cout << "Number of rows must be positive." << std::endl;
        return;
    }

    std::vector<std::vector<int>> triangle; // To store the rows of Pascal's Triangle

    for (int row_num = 0; row_num < n; ++row_num) {
        std::vector<int> row; // Current row

        for (int col = 0; col <= row_num; ++col) {
            if (col == 0 || col == row_num) {
                // First and last elements of each row are 1
                row.push_back(1);
            } else {
                // Each element is the sum of the two elements above it
                row.push_back(triangle[row_num - 1][col - 1] + triangle[row_num - 1][col]);
            }
        }

        triangle.push_back(row); // Add the current row to the triangle
    }

    // Print the triangle using print_vector
    std::cout << "Pascal's Triangle with " << n << " rows:" << std::endl;
    for (const auto& row : triangle) {
        print_vector(row);
    }
    std::cout << std::endl;
}







int main() {
    //Q1 test example
    Q1();




    //Q2 Test
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {-1, 0, 1};
    std::vector<int> vec3 = {}; // Empty vector

    // Print the vectors
    std::cout << "Vector 1: ";
    print_vector(vec1);

    std::cout << "Vector 2: ";
    print_vector(vec2);

    std::cout << "Vector 3: ";
    print_vector(vec3);

    //Q3 test
    Q3();

    //Q4.1 test
    std::cout << "Testing isprime function:" << std::endl;
    std::cout << "isprime(2) = " << isprime(2) << '\n';
    std::cout << "isprime(10) = " << isprime(10) << '\n';
    std::cout << "isprime(17) = " << isprime(17) << '\n';
    std::cout << std::endl;

    //Q4.2 test
    std::cout << "Testing factorize function:" << std::endl;
    std::cout << "Factors of 2: ";
    print_vector(factorize(2));

    std::cout << "Factors of 72: ";
    print_vector(factorize(72));

    std::cout << "Factors of 196: ";
    print_vector(factorize(196));
    std::cout << std::endl;

    //Q 4.3 test
    std::cout << "Testing prime_factorize function:" << std::endl;
    std::cout << "Prime factors of 2: ";
    print_vector(prime_factorize(2));

    std::cout << "Prime factors of 72: ";
    print_vector(prime_factorize(72));

    std::cout << "Prime factors of 196: ";
    print_vector(prime_factorize(196));
    std::cout << std::endl;



    //Q5 test
    std::cout << "Testing print_pascals_triangle function:" << std::endl;

    int n1 = 1;
    int n2 = 5;
    int n3 = 10;

    std::cout << "Number of rows: " << n1 << std::endl;
    print_pascals_triangle(n1);

    std::cout << "Number of rows: " << n2 << std::endl;
    print_pascals_triangle(n2);

    std::cout << "Number of rows: " << n3 << std::endl;
    print_pascals_triangle(n3);

    return 0;
}

