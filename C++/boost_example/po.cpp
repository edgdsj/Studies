#include <iostream>
#include <boost/program_options.hpp>
#include <vector>
#include <string>

namespace po = boost::program_options;

int main(int num_args, char** args)
{  
    // Declare the supported options.
po::options_description desc("Allowed options");
desc.add_options()
    ("help", "produce help message")
    ("compression", po::value<int>(), "set compression level")
    ("tune", po::value<std::vector<int>>()->multitoken(), "tune")
;

po::variables_map vm;
po::store(po::parse_command_line(num_args, args, desc), vm);  

if (vm.count("help")) {
    std::cout << desc << "\n";
    return 1;
}

if(vm.count("tune")){
    auto fds =  vm["tune"].as<std::vector<int>>();
    for(auto v : fds){
        std::cout << v << std::endl;
    }
}

if (vm.count("compression")) {
    std::cout << "Compression level was set to " 
 << vm["compression"].empty() << ".\n";
} else {
    std::cout << "Compression level was not set.\n";
}
    
}