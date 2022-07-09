#include "philo.h"

typedef struct thread_info {
	int philo_num;
	int	time_to_die;
	int	time_to_eat;
	int time_to_sleep;
	int	count_must_eat;
} t_info;

int	ft_try_init_info(t_info *thread_info, int argc, char **argv)
{
	if (argc != 5 || argc != 6)
	{
		printf("%s\n", "illegal argument");
		return (false);
	}

	// 필요시 int 이상 범위일 때 예외처리 해주기
	thread_info->philo_num = ft_atoi()

}

int	main(int argc, char **argv)
{
	t_info	thread_info;
	


	ft_try_init_info(&thread_info, argc, argv);

	//매개변수 가지는 거  초기화 해주기
	//철학자 만들고 그만큼 포크를 만듬


}
