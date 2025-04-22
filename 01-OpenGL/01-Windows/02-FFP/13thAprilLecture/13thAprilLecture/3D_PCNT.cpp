// OpenGL values for position, color, texcoords, normal for pyradmid and cube

// PYRAMID

// position
GLfloat pyramidVertices[] = 
{
	 // front
	 0.0f,  1.0f,  0.0f, // front-top
	-1.0f, -1.0f,  1.0f, // front-left
	 1.0f, -1.0f,  1.0f, // front-right
	 
	 // right
	 0.0f,  1.0f,  0.0f, // right-top
	 1.0f, -1.0f,  1.0f, // right-left
	 1.0f, -1.0f, -1.0f, // right-right

	 // back
	 0.0f,  1.0f,  0.0f, // back-top
	 1.0f, -1.0f, -1.0f, // back-left
	-1.0f, -1.0f, -1.0f, // back-right

	 // left
	 0.0f,  1.0f,  0.0f, // left-top
	-1.0f, -1.0f, -1.0f, // left-left
	-1.0f, -1.0f,  1.0f, // left-right
};

// color
GLfloat pyramidColors[] =
{
	// front
	1.0f, 0.0f, 0.0f, // front-top
	0.0f, 1.0f, 0.0f, // front-left
	0.0f, 0.0f, 1.0f, // front-right
	
	// right
	1.0f, 0.0f, 0.0f, // right-top
	0.0f, 0.0f, 1.0f, // right-left
	0.0f, 1.0f, 0.0f, // right-right
	
	// back
	1.0f, 0.0f, 0.0f, // back-top
	0.0f, 1.0f, 0.0f, // back-left
	0.0f, 0.0f, 1.0f, // back-right
	
	// left
	1.0f, 0.0f, 0.0f, // left-top
	0.0f, 0.0f, 1.0f, // left-left
	0.0f, 1.0f, 0.0f, // left-right
};

// texcoords
GLfloat pyramidTexcoords[] =
{
	// front
	0.5, 1.0, // front-top
	0.0, 0.0, // front-left
	1.0, 0.0, // front-right

	// right
	0.5, 1.0, // right-top
	1.0, 0.0, // right-left
	0.0, 0.0, // right-right

	// back
	0.5, 1.0, // back-top
	0.0, 0.0, // back-left
	1.0, 0.0, // back-right

	// left
	0.5, 1.0, // left-top
	1.0, 0.0, // left-left
	0.0, 0.0, // left-right
};

// normals
GLfloat pyramidNormals[] =
{
	 // front
	 0.000000f, 0.447214f,  0.894427f, // front-top
	 0.000000f, 0.447214f,  0.894427f, // front-left
	 0.000000f, 0.447214f,  0.894427f, // front-right
						    
	 // right			    
	 0.894427f, 0.447214f,  0.000000f, // right-top
	 0.894427f, 0.447214f,  0.000000f, // right-left
	 0.894427f, 0.447214f,  0.000000f, // right-right

	 // back
	 0.000000f, 0.447214f, -0.894427f, // back-top
	 0.000000f, 0.447214f, -0.894427f, // back-left
	 0.000000f, 0.447214f, -0.894427f, // back-right

	 // left
	-0.894427f, 0.447214f,  0.000000f, // left-top
	-0.894427f, 0.447214f,  0.000000f, // left-left
	-0.894427f, 0.447214f,  0.000000f, // left-right
};

GLfloat pyramid_PCNT[] =
{
	 // front
	 // position		 // color			// normals						  // texcoords
	 0.0f,  1.0f,  0.0f, 1.0f, 0.0f, 0.0f,  0.000000f, 0.447214f,  0.894427f, 0.5, 1.0,
	-1.0f, -1.0f,  1.0f, 0.0f, 1.0f, 0.0f,  0.000000f, 0.447214f,  0.894427f, 0.0, 0.0,
	 1.0f, -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,  0.000000f, 0.447214f,  0.894427f, 1.0, 0.0,
																   
	 // right													   
	 // position		 // color			// normals						  // texcoords
	 0.0f,  1.0f,  0.0f, 1.0f, 0.0f, 0.0f,  0.894427f, 0.447214f,  0.000000f, 0.5, 1.0,
	 1.0f, -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,  0.894427f, 0.447214f,  0.000000f, 1.0, 0.0,
	 1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f,  0.894427f, 0.447214f,  0.000000f, 0.0, 0.0,

	 // back			  
	 // position		 // color			// normals						  // texcoords
	 0.0f,  1.0f,  0.0f, 1.0f, 0.0f, 0.0f,  0.000000f, 0.447214f, -0.894427f, 0.5, 1.0,
	 1.0f, -1.0f, -1.0f, 0.0f, 1.0f, 0.0f,  0.000000f, 0.447214f, -0.894427f, 0.0, 0.0,
	-1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f,  0.000000f, 0.447214f, -0.894427f, 1.0, 0.0,

	 // left
	 // position		 // color			// normals						  // texcoords
	 0.0f,  1.0f,  0.0f, 1.0f, 0.0f, 0.0f, -0.894427f, 0.447214f,  0.000000f, 0.5, 1.0,
	-1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, -0.894427f, 0.447214f,  0.000000f, 1.0, 0.0,
	-1.0f, -1.0f,  1.0f, 0.0f, 1.0f, 0.0f, -0.894427f, 0.447214f,  0.000000f, 0.0, 0.0,
};

// CUBE :

// position
GLfloat cubeVertices[] =
{
	// front
	 1.0f,  1.0f,  1.0f, // top-right of front
	-1.0f,  1.0f,  1.0f, // top-left of front
	-1.0f, -1.0f,  1.0f, // bottom-left of front
	 1.0f, -1.0f,  1.0f, // bottom-right of front

	// right
	 1.0f,  1.0f, -1.0f, // top-right of right
	 1.0f,  1.0f,  1.0f, // top-left of right
	 1.0f, -1.0f,  1.0f, // bottom-left of right
	 1.0f, -1.0f, -1.0f, // bottom-right of right

	// back
	 1.0f,  1.0f, -1.0f, // top-right of back
	-1.0f,  1.0f, -1.0f, // top-left of back
	-1.0f, -1.0f, -1.0f, // bottom-left of back
	 1.0f, -1.0f, -1.0f, // bottom-right of back

	// left
	-1.0f,  1.0f,  1.0f, // top-right of left
	-1.0f,  1.0f, -1.0f, // top-left of left
	-1.0f, -1.0f, -1.0f, // bottom-left of left
	-1.0f, -1.0f,  1.0f, // bottom-right of left

	// top
	 1.0f,  1.0f, -1.0f, // top-right of top
	-1.0f,  1.0f, -1.0f, // top-left of top
	-1.0f,  1.0f,  1.0f, // bottom-left of top
	 1.0f,  1.0f,  1.0f, // bottom-right of top

	// bottom
	 1.0f, -1.0f,  1.0f, // top-right of bottom
	-1.0f, -1.0f,  1.0f, // top-left of bottom
	-1.0f, -1.0f, -1.0f, // bottom-left of bottom
	 1.0f, -1.0f, -1.0f, // bottom-right of bottom
};

GLfloat cubeColors[] =
{
	// front
	1.0f, 0.0f, 0.0f, // top-right of front
	1.0f, 0.0f, 0.0f, // top-left of front
	1.0f, 0.0f, 0.0f, // bottom-left of front
	1.0f, 0.0f, 0.0f, // bottom-right of front

	// right
	0.0f, 0.0f, 1.0f, // top-right of right
	0.0f, 0.0f, 1.0f, // top-left of right
	0.0f, 0.0f, 1.0f, // bottom-left of right
	0.0f, 0.0f, 1.0f, // bottom-right of right

	// back
	1.0f, 1.0f, 0.0f, // top-right of back
	1.0f, 1.0f, 0.0f, // top-left of back
	1.0f, 1.0f, 0.0f, // bottom-left of back
	1.0f, 1.0f, 0.0f, // bottom-right of back

	// left
	1.0f, 0.0f, 1.0f, // top-right of left
	1.0f, 0.0f, 1.0f, // top-left of left
	1.0f, 0.0f, 1.0f, // bottom-left of left
	1.0f, 0.0f, 1.0f, // bottom-right of left

	// top
	0.0f, 1.0f, 0.0f, // top-right of top
	0.0f, 1.0f, 0.0f, // top-left of top
	0.0f, 1.0f, 0.0f, // bottom-left of top
	0.0f, 1.0f, 0.0f, // bottom-right of top

	// bottom
	1.0f, 0.5f, 0.0f, // top-right of bottom
	1.0f, 0.5f, 0.0f, // top-left of bottom
	1.0f, 0.5f, 0.0f, // bottom-left of bottom
	1.0f, 0.5f, 0.0f, // bottom-right of bottom
};

GLfloat cubeTexcoords[] =
{
	// front
	1.0f, 1.0f, // top-right of front
	0.0f, 1.0f, // top-left of front
	0.0f, 0.0f, // bottom-left of front
	1.0f, 0.0f, // bottom-right of front

	// right
	1.0f, 1.0f, // top-right of right
	0.0f, 1.0f, // top-left of right
	0.0f, 0.0f, // bottom-left of right
	1.0f, 0.0f, // bottom-right of right

	// back
	1.0f, 1.0f, // top-right of back
	0.0f, 1.0f, // top-left of back
	0.0f, 0.0f, // bottom-left of back
	1.0f, 0.0f, // bottom-right of back

	// left
	1.0f, 1.0f, // top-right of left
	0.0f, 1.0f, // top-left of left
	0.0f, 0.0f, // bottom-left of left
	1.0f, 0.0f, // bottom-right of left

	// top
	1.0f, 1.0f, // top-right of top
	0.0f, 1.0f, // top-left of top
	0.0f, 0.0f, // bottom-left of top
	1.0f, 0.0f, // bottom-right of top

	// bottom
	1.0f, 1.0f, // top-right of bottom
	0.0f, 1.0f, // top-left of bottom
	0.0f, 0.0f, // bottom-left of bottom
	1.0f, 0.0f, // bottom-right of bottom
};

GLfloat cubeNormals[] =
{
	 // front surface
	 0.0f,  0.0f,  1.0f, // top-right of front
	 0.0f,  0.0f,  1.0f, // top-left of front
	 0.0f,  0.0f,  1.0f, // bottom-left of front
	 0.0f,  0.0f,  1.0f, // bottom-right of front

	 // right surface
	 1.0f,  0.0f,  0.0f, // top-right of right
	 1.0f,  0.0f,  0.0f, // top-left of right
	 1.0f,  0.0f,  0.0f, // bottom-left of right
	 1.0f,  0.0f,  0.0f, // bottom-right of right

	 // back surface
	 0.0f,  0.0f, -1.0f, // top-right of back
	 0.0f,  0.0f, -1.0f, // top-left of back
	 0.0f,  0.0f, -1.0f, // bottom-left of back
	 0.0f,  0.0f, -1.0f, // bottom-right of back

	 // left surface
	-1.0f,  0.0f,  0.0f, // top-right of left
	-1.0f,  0.0f,  0.0f, // top-left of left
	-1.0f,  0.0f,  0.0f, // bottom-left of left
	-1.0f,  0.0f,  0.0f, // bottom-right of left

	 // top surface
	 0.0f,  1.0f,  0.0f, // top-right of top
	 0.0f,  1.0f,  0.0f, // top-left of top
	 0.0f,  1.0f,  0.0f, // bottom-left of top
	 0.0f,  1.0f,  0.0f, // bottom-right of top

	 // bottom surface
	 0.0f, -1.0f,  0.0f, // top-right of bottom
	 0.0f, -1.0f,  0.0f, // top-left of bottom
	 0.0f, -1.0f,  0.0f, // bottom-left of bottom
	 0.0f, -1.0f,  0.0f, // bottom-right of bottom
};

GLfloat cube_PCNT[] =
{
	// front
	// position				// color			 // normals				// texcoords
	 1.0f,  1.0f,  1.0f,	1.0f, 0.0f, 0.0f,	 0.0f,  0.0f,  1.0f,	1.0f, 1.0f,
	-1.0f,  1.0f,  1.0f,	1.0f, 0.0f, 0.0f,	 0.0f,  0.0f,  1.0f,	0.0f, 1.0f,
	-1.0f, -1.0f,  1.0f,	1.0f, 0.0f, 0.0f,	 0.0f,  0.0f,  1.0f,	0.0f, 0.0f,
	 1.0f, -1.0f,  1.0f,	1.0f, 0.0f, 0.0f,	 0.0f,  0.0f,  1.0f,	1.0f, 0.0f,
						 
	// right			 
	// position				// color			 // normals				// texcoords
	 1.0f,  1.0f, -1.0f,	0.0f, 0.0f, 1.0f,	 1.0f,  0.0f,  0.0f,	1.0f, 1.0f,
	 1.0f,  1.0f,  1.0f,	0.0f, 0.0f, 1.0f,	 1.0f,  0.0f,  0.0f,	0.0f, 1.0f,
	 1.0f, -1.0f,  1.0f,	0.0f, 0.0f, 1.0f,	 1.0f,  0.0f,  0.0f,	0.0f, 0.0f,
	 1.0f, -1.0f, -1.0f,	0.0f, 0.0f, 1.0f,	 1.0f,  0.0f,  0.0f,	1.0f, 0.0f,
						 
	// back				 
	// position				// color			 // normals				// texcoords
	 1.0f,  1.0f, -1.0f,	1.0f, 1.0f, 0.0f,	 0.0f,  0.0f, -1.0f,	1.0f, 1.0f,
	-1.0f,  1.0f, -1.0f,	1.0f, 1.0f, 0.0f,	 0.0f,  0.0f, -1.0f,	0.0f, 1.0f,
	-1.0f, -1.0f, -1.0f,	1.0f, 1.0f, 0.0f,	 0.0f,  0.0f, -1.0f,	0.0f, 0.0f,
	 1.0f, -1.0f, -1.0f,	1.0f, 1.0f, 0.0f,	 0.0f,  0.0f, -1.0f,	1.0f, 0.0f,
						 
	// left				 
	// position				// color			 // normals				// texcoords
	-1.0f,  1.0f,  1.0f,	1.0f, 0.0f, 1.0f,	-1.0f,  0.0f,  0.0f,	1.0f, 1.0f,
	-1.0f,  1.0f, -1.0f,	1.0f, 0.0f, 1.0f,	-1.0f,  0.0f,  0.0f,	0.0f, 1.0f,
	-1.0f, -1.0f, -1.0f,	1.0f, 0.0f, 1.0f,	-1.0f,  0.0f,  0.0f,	0.0f, 0.0f,
	-1.0f, -1.0f,  1.0f,	1.0f, 0.0f, 1.0f,	-1.0f,  0.0f,  0.0f,	1.0f, 0.0f,
						 
	// top				 
	// position				// color			 // normals				// texcoords
	 1.0f,  1.0f, -1.0f,	0.0f, 1.0f, 0.0f,	 0.0f,  1.0f,  0.0f,	1.0f, 1.0f,
	-1.0f,  1.0f, -1.0f,	0.0f, 1.0f, 0.0f,	 0.0f,  1.0f,  0.0f,	0.0f, 1.0f,
	-1.0f,  1.0f,  1.0f,	0.0f, 1.0f, 0.0f,	 0.0f,  1.0f,  0.0f,	0.0f, 0.0f,
	 1.0f,  1.0f,  1.0f,	0.0f, 1.0f, 0.0f,	 0.0f,  1.0f,  0.0f,	1.0f, 0.0f,
						 
	// bottom			 
	// position				// color			 // normals				// texcoords
	 1.0f, -1.0f,  1.0f,	1.0f, 0.5f, 0.0f,	 0.0f, -1.0f,  0.0f,	1.0f, 1.0f,
	-1.0f, -1.0f,  1.0f,	1.0f, 0.5f, 0.0f,	 0.0f, -1.0f,  0.0f,	0.0f, 1.0f,
	-1.0f, -1.0f, -1.0f,	1.0f, 0.5f, 0.0f,	 0.0f, -1.0f,  0.0f,	0.0f, 0.0f,
	 1.0f, -1.0f, -1.0f,	1.0f, 0.5f, 0.0f,	 0.0f, -1.0f,  0.0f,	1.0f, 0.0f,
};
