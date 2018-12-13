#version 330 core
out vec4 FragColor;

in vec3 outNormal;

void main()
{
    vec3 lightDirection = normalize(vec3(-0.3 , 1.0, 1.0));

    vec3 ka = vec3(1.0, 1.0, 1.0);          // ambient reflection color
    vec3 Ia = vec3(0.05, 0.05, 0.05);       // ambient illumination color
    vec3 kd = vec3(0.4, 0.1, 0.8);          // diffuse surface reflection color
    vec3 Id = vec3(1.0, 1.0, 1.0);          // diffuse illumination color
    vec3 ks = vec3(1.0, 1.0, 1.0);          // specular surface reflection color
    vec3 Is = vec3(1.0, 1.0, 1.0);          // specular illumination color
    float n = 10;                           // the "shininess" parameter

    vec3 V = vec3(0.0, 0.0, 1.0);       //Direction of the viewer. ALWAYS (0,0,1)!

    vec3 R = 2.0*dot(outNormal, lightDirection)*outNormal - lightDirection; //Could also use the function reflect();   // R is the computed reflection direction

    float dotNL = max(dot(outNormal, lightDirection), 0.0);  // Scalar product between light direction and normal. If negative, set to zero.
    float dotRV = max(dot(R,V), 0.0);                           //Scalar product between computed reflection direction and view direction
    if (dotNL == 0.0) dotRV = 0.0;                              //Do not show highlight on the dark side

    vec3 shadedcolor = Ia*ka + Id*kd*dotNL + Is*ks*pow(dotRV, n);   //Final color (for each pixel)
    FragColor = vec4(shadedcolor, 1.0); //Using colors for surface colors
} 