#include<stdio.h>
#include<gegl.h>
#include<math.h>
int main(int argc , char **argv)
{
  GeglNode *load, *laplace, *gegl,  *write;
  gegl_init (&argc, &argv);

  if(argv[1]==NULL || argv[2]==NULL)
    {
       g_print ("\nEdge Detection using GEGL Operation.");
       g_print ("\nUsage: %s <input-image> <output-image>\n", argv[0]);
       return 1;
    }
  
  gegl = gegl_node_new ();
  
  load = gegl_node_new_child (gegl,
                             "operation", "gegl:load",
                             "path", argv[1],
                             NULL);
 
 
  laplace = gegl_node_new_child (gegl,
                              "operation", "gegl:edge-laplace",
                              NULL);
  write = gegl_node_new_child (gegl,
                              "operation", "gegl:save",
                              "path", argv[2],
                              NULL);
  gegl_node_link_many (load, laplace, write, NULL);
  gegl_node_process (write);
  

  g_object_unref (gegl);
  
  gegl_exit();
  return 0;
}
                              
