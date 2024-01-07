#!/bin/bash

# Check if Homebrew is installed
which -s brew
if [[ $? != 0 ]] ; then
    # Install Homebrew
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
fi

# Update Homebrew
brew update

# Install Crypto++ library
brew install cryptopp

# Environment setup
echo "export CRYPTOPP_INCLUDE_DIR=\"/opt/homebrew/Cellar/cryptopp/8.9.0/include\"" >> ~/.bash_profile
echo "export CRYPTOPP_LIB_DIR=\"/opt/homebrew/Cellar/cryptopp/8.9.0/lib\"" >> ~/.bash_profile
echo "Please restart your terminal or run 'source ~/.bash_profile' to update environment variables."
