#include "ros/ros.h"
#include "task_4/PrimeNums.h"

bool add(task_4::PrimeNums::Request  &req,
         task_4::PrimeNums::Response &res)
{
  int n = req.N;
  int i,j,k=0,c;
  for(i=1;i<n;i++)
  {
	c=0;
	for(j=1;j<=i;j++)
	{
		if(i%j==0)
			c++;
	}
	if(c==2)
		res.primes[k++]=i;
  }
  ROS_INFO("request: N = %ld", (long int)req.N);
  ROS_INFO("sending back response:");
  for(i=0;i<k;i++)
  {
  	ROS_INFO("%ld ", (long int)res.primes[i]);
  }
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("prime_nums", add);
  ROS_INFO("Checking for Primes.");
  ros::spin();

  return 0;
}
