printf가 버퍼를 가지지 말아야 한다는 이유는 아래코드에서 p_pa 줄바꿈이 없는 경우 출력이 안 되서
stdin에 printf가 출력을 하는데 얘는 기본적으로 라인 버퍼링 그래서 줄바꿈이 없는 애는 fflush(stdout)을 해야함

	while (i < n)
	{
		p_pa = get_next_line(fd);
		printf("%s", p_pa);
		fflush(stdout);
		free(p_pa);
		i++;
	}