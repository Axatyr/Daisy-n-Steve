#version 330 core
layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec4 aColor; // the color variable has attribute position 1
  
out vec4 ourColor; // output a color to the fragment shader
uniform mat4 Projection;  //vARIABILE DI TIPO uniform, rimane la stessa per ogni vertice della primitiva e viene passata dall'esterno
uniform mat4 Model;

uniform int sceltaVS;
uniform float time;

void main()
{
//Trasformazione dei vertici dalle coordinate nel sistema di riferimento dell'oggetto (apos), al sistema di riferimento del mondo (premoltiplicazione 
// per Model) e successivamente proiettate nel cubo di centro l'origine e lato lungo 2, con x,y,z che variano tra -1 ed 1- (premoltiplicazione 
//per la matrice Projection)
    if (sceltaVS==1)
    {
        vec4	v =  vec4(aPos, 1.0);
        float	offset = 0.3*sin(0.01*time+5.0*v.y);
		v.x=v.x+offset;

        gl_Position = Projection*Model*v;
    }  
    else
    {
        gl_Position = Projection*Model*vec4(aPos, 1.0);
    }
    ourColor = aColor; // set ourColor to the input color we got from the vertex data
}  

