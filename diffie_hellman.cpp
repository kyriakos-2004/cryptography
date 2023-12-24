#include<iostream>
#include<cstdio>

class DiffieHellman
{
public:
    uint64_t common_prime_number, primitive_root, 
             alice_secret_number, alice_private_key, 
             bob_secret_number, bob_private_key, 
             alice_public_key, bob_public_key;

    DiffieHellman(uint64_t common_prime, uint64_t primitive_root, uint64_t secret_num_1, uint64_t secret_num_2)
    {
        alice_private_key = power(primitive_root, secret_num_1, common_prime);
        bob_private_key = power(primitive_root, secret_num_2, common_prime);
        alice_public_key = power(bob_private_key, secret_num_1, common_prime);
        bob_public_key = power(alice_private_key, secret_num_2, common_prime);
    }
    
    uint64_t power(uint64_t base, uint64_t exponent, uint64_t modulo)
    {
        if (exponent == 1)
        {
            return base;
        }

        uint64_t s = power(base, exponent / 2, modulo);
        if (exponent % 2 == 0)
        {
            return (s * s) % modulo;
        }
        else
        {
            return (((s * s) % modulo) * base) % modulo;
        }
    }
};

int 
main()
{
    uint64_t common_prime_number = 0 , primitive_root = 0, 
             alice_secret_number = 0, alice_private_key = 0,
             bob_secret_number = 0, bob_private_key = 0,
             alice_public_key = 0, bob_public_key = 0;

    std::cout << "Enter the common prime number and primitive root that Alice And Bob agreed on: ";
    std::cin >> common_prime_number >> primitive_root;
    
    std::cout << "\n";
    std::cout << "Enter the secret number Alice chose: ";
    std::cin >> alice_secret_number;

    std::cout << "\n";
    std::cout << "Enter the secret number Bob chose: ";
    std::cin >> bob_secret_number;
    
    DiffieHellman diffie_hellmann(common_prime_number, primitive_root, alice_secret_number, bob_secret_number);
    
    std::cout << "\n";
    std::cout << "Alice's private key: " << diffie_hellmann.alice_private_key << "\n";
    std::cout << "Bob's private key: " << diffie_hellmann.bob_private_key << "\n";
    std::cout << "\n";
    std::cout << "Alice's public key: " << diffie_hellmann.alice_public_key << "\n";
    std::cout << "Bob's public key: " << diffie_hellmann.bob_public_key << "\n";

    return 0;
}