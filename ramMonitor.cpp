#include<thread>//thread
#include<fstream>//file
#include<iostream>//i/o
#include<chrono> //time


bool getMemoryStatus(unsigned long long& totalMemory,unsigned long long& availableMemory)
{
	std::ifstream meminfo("proc/meminfo");
	if(!meminfo.is_open())
	{
		return false;//meminfo file is not opened
	}
	std::string key;
	unsigned long long value;
	std::string unit;

	while(meminfo >> key >> value >> unit)
	{
		if(key == "Memtotal:")
		{
			totalMemory = value / 1024;
		}else if(key == "Memavailable:")
		{
			availableMemory = value / 1024;
			break;
		}
		
	}
	return true;
}

void printMemoryUsageBar()
{

	const int barWidth =  50;
	while(true)
	{
		unsigned long long totalMemory = 0,availableMemory = 0;
		if(getMemoryStatus(totalMemory,availableMemory))
		{
			unsigned long long usedMemory = totalMemory - availableMemory;
			float memoryUsagePercentage = static_cast<float>(usedMemory) / totalMemory;
			
			std::cout << "\033[2j\033[H";

			std::cout << "Total Memory: "<< totalMemory <<" MB\n";
			std::cout << "Used Memory: "<< usedMemory<<" MB\n";
			std::cout << "Free Memory: "<< totalMemory - usedMemory <<" MB\n";
			std::cout <<"Memory Usage: "<< static_cast<int>(memoryUsagePercentage * 100)<<"%\n";			
			std::cout << "[";
			int pos = barWidth * memoryUsagePercentage;
			for(int i=0; i<barWidth;++i)
			{
				if(i < pos) std::cout<<"=";
				else if(i==pos) std::cout<<">";
				else std::cout << " ";
			}
		std::cout<<"]" << static_cast<int>(memoryUsagePercentage * 100) << "%\r";
		std::cout.flush();
		
		std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		else
		{
			std::cout << "Failed to get memory status. \n";
			break;
		}
	}
		 
}

int main(){

	printMemoryUsageBar();
	return 0;

}
