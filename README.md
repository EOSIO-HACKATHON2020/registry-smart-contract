# registry-smart-contract

Registry smart contract is design to create, store forms and store responses on existing forms in EOSIO blockchain.

# Dependencies

* eosio 2.0^
* eosio.cdt 1.7^
* cmake 3.5^

# Compiling

```
mkdir build
cd build
cmake ..
make
```

# Run units

```
./scripts/build_contract_n_units.sh
./scripts/run_units.sh
```

# Deploying

```
cleos set contract <your_account> ./build/registry registry.wasm registry.abi
```