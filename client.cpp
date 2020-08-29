#include "ros/ros.h"
#include "task_4/PrimeNums.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "client");
  if (argc != 2)
  {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }
  int i;
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<task_4::PrimeNums>("prime_nums");
  task_4::PrimeNums srv;
  srv.request.N = atoll(argv[1]);
  //srv.request.b = atoll(argv[2]);
  if (client.call(srv))
  {
	ROS_INFO("Primes less than the given num: ");
	for(i=0;i<srv.response.primes.size();i++)
	{    
		if(srv.response.primes[i]!=0)
			ROS_INFO("%ld ", (long int)srv.response.primes[i]);
	}
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}
