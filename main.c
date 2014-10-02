/*
** main.c for broggi_t in /home/broggi_t/rendu/ex_4
** 
** Made by broggi_t
** Login   <broggi_t@epitech.eu>
** 
** Started on  Thu May 22 12:03:57 2014 broggi_t
** Last update Thu May 22 13:57:53 2014 broggi_t
*/

#include <unistd.h>
#include <fcntl.h>
#include "sopipa.h"

static inline int	sopipa(const char **av)
{
  int			pipefd[2];
  int			infd;
  int			outfd;
  pid_t			pid;

  return (((((infd = open(FILE1, O_RDONLY)) == -1
	     || (outfd = creat(FILE2, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1
	     || dup2(infd, 0) == -1
	     || pipe(pipefd) == -1
	     || (pid = fork()) == -1))
	   || ((pid == 0)
	       && ((close(pipefd[0]) == -1
		    || dup2(pipefd[1], 1) == -1
		    || execlp("/bin/sh", "/bin/sh", "-c", CMD1, (void *)0) == -1)))
	   || ((close(pipefd[1]) == -1
		|| dup2(pipefd[0], 0) == -1
		|| dup2(outfd, 1) == -1
		|| execlp("/bin/sh", "/bin/sh", "-c", CMD2, (void *)0) == -1))) ?
	  (FAILURE) : (SUCCESS));
}

int			main(const int ac, const char **av)
{
  return ((ac < 5) ? FAILURE : sopipa(av));
}
