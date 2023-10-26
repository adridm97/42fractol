

#include "fractol.h"

void  create_window(t_list *program)
{
  program->ptr = mlx_init();
  program->win = mlx_new_window(program->ptr, 1080, 600, "fract-ol");
}

int main()
{
  t_list program;

  create_window(&program);
  mlx_loop(program.ptr);
  return (0);
}
