# Bank System (C++)

A simple console-based bank system written in C++ using OOP. Accounts are kept in a `vector<Account>` and every operation is verified by account ID and PIN.

## Features

- **Create Account**: name, initial balance, and PIN. A unique ID is generated and shown after creation.
- **Delete Account**: requires ID and PIN.
- **Deposit**: add money to an account (ID + PIN required).
- **Withdraw**: checks that the balance is sufficient.
- **Transfer**: move money from one account to another. The receiver is verified before any money is withdrawn, so no money is lost on a wrong receiver ID.
- **Get Info**: shows account name, ID, and balance (ID + PIN required).

## Validation

- Wrong ID: `Wrong ID`
- Wrong PIN: `Wrong pin`
- Amount less than or equal to 0 in deposit, withdraw, and transfer: `Invalid amount`
- Negative initial balance when creating an account is rejected.
- Transfer to the same account is rejected.
- Insufficient balance: the current balance is displayed.

## Project Structure

```
.
├── Account.h        # Account class declaration
├── Account.cpp      # Account class implementation
├── bank_system.cpp  # main() and the console menu
└── README.md
```

## Design Notes

- Operations such as `Deposit`, `Withdraw`, `Transfer`, `deleteAccount`, `display`, and `findAccount` are **static** functions, because they work on the `vector` of accounts and do not need a specific object.
- `findAccount` searches by ID and returns the index in the vector (or `-1` if not found).
- Each operation finds the account first, then checks the PIN with `checkpin`.
- IDs are generated with a static counter and are never reused after deleting an account.

## Build and Run

Requires a C++ compiler (g++, clang, or MSVC).

```bash
g++ bank_system.cpp Account.cpp -o bank_system
./bank_system
```

On Windows:

```bash
g++ bank_system.cpp Account.cpp -o bank_system.exe
bank_system.exe
```

## Usage

```
===== Bank System =====
1. Create Account
2. Delete Account
3. Deposit
4. Withdraw
5. Transfer
6. Get info
0. Exit
Choose:
```

Example: create an account named `Ahmed Ali` with 500 and PIN `1234`. The program prints the account ID. Use this ID and the PIN for all later operations.

## Known Limitations

- Data is stored in memory only and is lost when the program exits.
- Entering letters where a number is expected can break input reading.
- PINs are stored as plain text, and `Get info` prints the PIN. This is fine for a learning project, but not for a real system.

## Possible Improvements

- Save and load accounts from a file.
- Safer input handling for non-numeric input.
- Hash the PIN instead of storing it as plain text.
- Transaction history for each account.
- Mark getters as `const`.