#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shaders.h"
#include "Model.h"
#include "Texture.h"


void configScene();
void renderScene();

//Dibujado de objetos, materiales, texturas y luces
void drawObject(Model model, glm::vec3 color, glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawObjectMat(Model model, Material material, glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawObjectTex(Model model, Textures textures, glm::mat4 P, glm::mat4 V, glm::mat4 M);
void setLights (glm::mat4 P, glm::mat4 V);

// Modelado Coche
void drawCoche(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawParachoques(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawParteDelanteraCoche(glm::mat4 P,glm::mat4 V,glm::mat4 M);
void infraestructuraDelanteCoche(glm::mat4 P,glm::mat4 V,glm::mat4 M);
void drawSillaCoche(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void capo(glm::mat4 P,glm::mat4 V, glm::mat4 M);
void logoCoche(glm::mat4 P,glm::mat4 V, glm::mat4 M);
void marcoCristalDelantero(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawPuerta(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void lateralIzquierdoCoche(glm::mat4 P,glm::mat4 V,glm::mat4 M);
void lateralDerechoCoche(glm::mat4 P,glm::mat4 V,glm::mat4 M);
void drawVolante(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void volante(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void parteDeAtrasCoche(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void parteDeAbajoCohe(glm::mat4 P,glm::mat4 V,glm::mat4 M);
void manillar(glm::mat4 P,glm::mat4 V,glm::mat4 M);
void manillarDerecho(glm::mat4 P,glm::mat4 V,glm::mat4 M);
void drawLucesLaterales(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawLucesDelanteras(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawParteAtrasMaletero(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawRetrovisor(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawPaloRetrovisor(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawEspejoRetrovisor(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawTuboEscape(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawMaletero(glm::mat4 P,glm::mat4 V,glm::mat4 M);
void drawAsientoDelantero(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawAsientoTrasero(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void AsientoIzquierdo(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void AsientoDerecho(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawRuedas(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void Llanta(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawCristales(glm::mat4 P,glm::mat4 V,glm::mat4 M);
void Ventanas(glm::mat4 P,glm::mat4 V,glm::mat4 M);
void drawParabrisas(glm::mat4 P,glm::mat4 V,glm::mat4 M);
void drawTecho(glm::mat4 P,glm::mat4 V,glm::mat4 M);

// Modelado escena

void drawEscena(glm::mat4 P, glm::mat4 V, glm::mat4 M);

void drawFarola(glm::mat4 P,glm::mat4 V, glm::mat4 M);
void drawBaseFarola(glm::mat4 P,glm::mat4 V, glm::mat4 M);
void drawPaloFarola(glm::mat4 P,glm::mat4 V, glm::mat4 M);
void drawCabezaFarola(glm::mat4 P,glm::mat4 V, glm::mat4 M);

void drawCarretera(glm::mat4 P, glm::mat4 V, glm::mat4 M);
void drawValla(glm::mat4 P, glm::mat4 V, glm::mat4 M);

void drawBank(glm::mat4 P,glm::mat4 V,glm::mat4 M);
void drawStop(glm::mat4 P,glm::mat4 V,glm::mat4 M);
void drawTronco(glm::mat4 P,glm::mat4 V,glm::mat4 M);
void drawArboles(glm::mat4 P,glm::mat4 V,glm::mat4 M);
void drawArdillas(glm::mat4 P,glm::mat4 V,glm::mat4 M);
void drawCasa(glm::mat4 P,glm::mat4 V,glm::mat4 M);
void drawPaisaje(glm::mat4 P,glm::mat4 V,glm::mat4 M);

// Animacion
void MovimientoArdillas();
void ControlCoche();

void funFramebufferSize(GLFWwindow* window, int width, int height);
void funKey(GLFWwindow* window, int key  , int scancode, int action, int mods);
void funScroll( GLFWwindow * ventana, double xoffset, double yoffset);
static  void funCursorPosition( GLFWwindow * ventana, double xpos, double ypos);
void character_callback(GLFWwindow* window, unsigned int codepoint);


// Shaders
Shaders shaders;

// Modelos
Model plane;
Model triangle;
Model cylinder;
Model cone;
Model torus;
Model sphere;
Model cube;
Model monkey;
Model prueba;
Model bank;
Model stop;
Model tronco;
Model arbol;
Model ardilla;

//Luces
#define   NLD 1
#define   NLP 4
#define   NLF 6
Light   lightG;
Light     lightD[NLD];
Light     lightP[NLP];
Light     lightF[NLF];
Material  mluz;
Material cyan;


//Imagenes(Texturas)
Texture imgNoEmissive;
Texture imgRuby;
Texture imgWood;
Texture imgWoodNormal;

Texture imgGold;

Texture imgRoad;
Texture imgRoadSpecular;
Texture imgRoadNormal;

Texture imgNeumatico;

Texture imgCesped;
Texture imgCespedSpecular;
Texture imgCespedNormal;

Texture imgAcera;
Texture imgAceraSpecular;
Texture imgAceraNormal;

Texture imgMetal;
Texture imgMetalNegro;
Texture imgRejillaBlanco;
Texture imgRejillaMetal;
Texture imgFibraCarbono;
Texture imgCueroNegro;
Texture imgCueroMarron;
Texture imgTigre;

Texture imgBenchColor;
Texture imgBenchNormal;
Texture imgBenchRugoso;

Texture imgStopColor;
Texture imgStopNormal;
Texture imgStopRugoso;

Texture imgTroncoColor;
Texture imgTroncoNormal;
Texture imgTroncoSpecular;

Texture imgArbolColor;
Texture imgArdilla;

Texture imgCasa;
Texture imgCasaNormal;
Texture imgPaisajeModerno;
Texture imgPaisajeModernoNormal;

//Texturas
Textures texWood;
Textures texGold;
Textures texRoad;
Textures texRuby;
Textures texNeumatico;
Textures texCesped;
Textures texAcera;
Textures texMetal;
Textures texMetalNegro;
Textures texRejillaBlanco;
Textures texRejillaMetal;
Textures texFibraCarbono;
Textures texCueroNegro;
Textures texCueroMarron;
Textures texTigre;
Textures texBench;
Textures texStop;
Textures texTronco;
Textures texArbol;
Textures texArdilla;
Textures texCasa;
Textures texPaisajeModerno;

// Viewport
int w = 750;
int h = 750;

//Movimiento coche
float wMov = 0.0;
float aMov = 0.0;

//Camara Coche
bool camaraCoche = false;
float xEye = 0.0;
float yEye = 0.0;
float zEye = 0.0;

float xCenter = -6.0;
float yCenter = 1.0;
float zCenter = 0.0;

// Animaciones
float ROT_MALETERO = 0.0;

//Rotacion segun el tiempo

float valorFovy=40.0;
int techo=0;
float alturaVentana=4.2;
float alturaMaletero=3.3;

double alphaX=90.0;
double alphaY=30.0;

//Movimiento ardilla
float asomar=90.0;
float asomar2=0.0;

//Modo del dia
bool noche=false;

//Luz ambiente
float ambiente=2.0;

//Luz direccional
float direccional=8.0;

//Luces coches
float delanteraA = 2.0;
float delanteraD = 5.0;
float delanteraS = 2.0;
float traseraA = 1.2;
float traseraD = 2.0;
float traseraS = 1.0;
float lateralA = 1.0;
float lateralAy = 0.5;
float lateralD = 2.0;
float lateralDy = 1.0;
float lateralS = 1.0;
float lateralSy = 0.5;

//Luces farolas
float farolaA = 6.0;
float farolaD = 6.0;
float farolaS = 5.0;

//Rotaciones de elementos del vehiculo
float rotVolante=0.0;
float rotRuedas=0.0;
float rotPuerta=0.0;

//Movimiento de la puerta al abrir/cerrar
float trasPuertax=0.0;
float trasPuertaz=0.0;

// Diferentes escenas con distinta disposicion de los elementos
int numeroEscena=0;

int main() {

    // Inicializamos GLFW
    if(!glfwInit()) return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Creamos la ventana
    GLFWwindow* window;
    window = glfwCreateWindow(w, h, "PRACTICA FINAL", NULL, NULL);
    if(!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);

    // Inicializamos GLEW
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if(GLEW_OK != err) {
        std::cout << "Error: " << glewGetErrorString(err) << std::endl;
        return false;
    }
    std::cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;
    const GLubyte *oglVersion = glGetString(GL_VERSION);
    std::cout <<"This system supports OpenGL Version: " << oglVersion << std::endl;

    // Configuramos los CallBacks
    glfwSetFramebufferSizeCallback(window, funFramebufferSize);
    glfwSetKeyCallback(window, funKey);
    glfwSetScrollCallback (window, funScroll);
    glfwSetCursorPosCallback (window, funCursorPosition);
    glfwSetCharCallback(window, character_callback);
    //glfwSetMouseButtonCallback(window, funMouseButton);;

    // Entramos en el bucle de renderizado
    configScene();
    while(!glfwWindowShouldClose(window)) {
        renderScene();
        glfwSwapBuffers(window);
        glfwPollEvents();

    }
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

void configScene() {

    // Test de profundidad
    glEnable(GL_DEPTH_TEST);
    glPolygonOffset(1.0,1.0);

    // Transparencias
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Shaders
    shaders.initShaders("resources/shaders/vshader.glsl","resources/shaders/fshader.glsl");

    // Modelos
    plane.initModel("resources/models/plane.obj");
    triangle.initModel("resources/models/triangle.obj");
    cylinder.initModel("resources/models/cylinder.obj");
    cone.initModel("resources/models/cone.obj");
    torus.initModel("resources/models/torus.obj");
    sphere.initModel("resources/models/sphere.obj");
    cube.initModel("resources/models/cube.obj");
    monkey.initModel("resources/models/monkey.obj");
    prueba.initModel("resources/models/prueba.obj");
    bank.initModel("resources/models/bank.obj");
    stop.initModel("resources/models/stopsign.obj");
    tronco.initModel("resources/models/tronco.obj");
    arbol.initModel("resources/models/arbol.obj");
    ardilla.initModel("resources/models/ardilla.obj");

    //Imagenes(Texturas)
    imgNoEmissive.initTexture("resources/textures/imgNoEmissive.png");
    imgWood.initTexture("resources/textures/madera.jpg");
    imgWoodNormal.initTexture("resources/textures/imgWoodNormal.jpeg");

    imgGold.initTexture("resources/textures/imgGold.png");

    imgRoad.initTexture("resources/textures/carretera3.png");
    imgRoadSpecular.initTexture("resources/textures/carretera_specular.jpg");
    imgRoadNormal.initTexture("resources/textures/carretera_normal.jpg");


    imgRuby.initTexture("resources/textures/imgRuby.png");
    imgNeumatico.initTexture("resources/textures/neumatico2.jpg");

    imgCesped.initTexture("resources/textures/cesped.jpg");
    imgCespedSpecular.initTexture("resources/textures/cesped_specular.png");
    imgCespedNormal.initTexture("resources/textures/cesped_normal.png");

    imgAcera.initTexture("resources/textures/acera.jpg");
    imgAceraSpecular.initTexture("resources/textures/imgAceraSpecular.png");
    imgAceraNormal.initTexture("resources/textures/imgAceraNormal.png");


    imgMetal.initTexture("resources/textures/metal.jpg");
    imgMetalNegro.initTexture("resources/textures/metalNegro.jpg");
    imgRejillaBlanco.initTexture("resources/textures/rejilla.png");
    imgRejillaMetal.initTexture("resources/textures/rejilla2.jpg");
    imgFibraCarbono.initTexture("resources/textures/fibraCarbono.jpg");
    imgCueroNegro.initTexture("resources/textures/cuero.jpg");
    imgCueroMarron.initTexture("resources/textures/cueroMarron.jpg");
    imgTigre.initTexture("resources/textures/tigre.jpg");

    imgBenchColor.initTexture("resources/textures/bench_colorBasico.png");
    imgBenchNormal.initTexture("resources/textures/bench_normal.png");
    imgBenchRugoso.initTexture("resources/textures/bench_rugoso.png");

    imgStopColor.initTexture("resources/textures/stop_colorBasico.png");
    imgStopNormal.initTexture("resources/textures/stop_normal.png");
    imgStopRugoso.initTexture("resources/textures/stop_rugoso.png");

    imgTroncoColor.initTexture("resources/textures/tronco_difusa.jpg");
    imgTroncoNormal.initTexture("resources/textures/tronco_normal.jpg");
    imgTroncoSpecular.initTexture("resources/textures/tronco_specular.jpg");

    imgArbolColor.initTexture("resources/textures/arbol_difusa.jpg");
    imgArdilla.initTexture("resources/textures/ardilla.jpg");

    imgCasa.initTexture("resources/textures/paisajeModerno.jpg");
    imgCasaNormal.initTexture("resources/textures/casa_normal.png");

    imgPaisajeModerno.initTexture("resources/textures/paisajeModernoNoche.jpg");
    imgPaisajeModernoNormal.initTexture("resources/textures/paisajeModerno_normal.png");

    //Materiales
    mluz.ambient   = glm::vec4(0.0, 0.0, 0.0, 1.0);
    mluz.diffuse   = glm::vec4(0.0, 0.0, 0.0, 1.0);
    mluz.specular  = glm::vec4(0.0, 0.0, 0.0, 1.0);
    mluz.emissive  = glm::vec4(1.0, 1.0, 1.0, 1.0);
    mluz.shininess = 1.0;

    //textura oro
    texGold.diffuse   = imgGold.getTexture();
    texGold.specular  = imgGold.getTexture();
    texGold.emissive  = imgNoEmissive.getTexture();
    texGold.normal    = 0;
    texGold.shininess = 51.2;

    //textura madera
    texWood.diffuse   = imgWood.getTexture();
    texWood.specular  = imgWood.getTexture();
    texWood.emissive  = imgNoEmissive.getTexture();
    texWood.normal    = imgWoodNormal.getTexture();
    texWood.shininess =76.8;

    //textura carretera
    texRoad.diffuse   = imgRoad.getTexture();
    texRoad.specular  = imgRoadSpecular.getTexture();
    texRoad.emissive  = imgNoEmissive.getTexture();
    texRoad.normal    = 0;
    texRoad.shininess =12.8;

    //textura ruby
    texRuby.diffuse   = imgRuby.getTexture();
    texRuby.specular  = imgRuby.getTexture();
    texRuby.emissive  = imgNoEmissive.getTexture();
    texRuby.normal    = 0;
    texRuby.shininess = 76.8;

    //textura Neumatico
    texNeumatico.diffuse   = imgNeumatico.getTexture();
    texNeumatico.specular  = imgNeumatico.getTexture();
    texNeumatico.emissive  = imgNoEmissive.getTexture();
    texNeumatico.normal    = 0;
    texNeumatico.shininess = 76.8;

    //textura Cesped
    texCesped.diffuse   = imgCesped.getTexture();
    texCesped.specular  = imgCespedSpecular.getTexture();
    texCesped.emissive  = imgNoEmissive.getTexture();
    texCesped.normal    = imgCespedNormal.getTexture();
    texCesped.shininess = 76.8;

    //textura Acera
    texAcera.diffuse   = imgAcera.getTexture();
    texAcera.specular  = imgAceraSpecular.getTexture();
    texAcera.emissive  = imgNoEmissive.getTexture();
    texAcera.normal    = imgAceraNormal.getTexture();
    texAcera.shininess = 76.8;

    //Textura Metal
    texMetal.diffuse   = imgMetal.getTexture();
    texMetal.specular  = imgMetal.getTexture();
    texMetal.emissive  = imgNoEmissive.getTexture();
    texMetal.normal    = 0;
    texMetal.shininess = 76.8;

    //Textura Rejilla Blanco
    texRejillaBlanco.diffuse   = imgRejillaBlanco.getTexture();
    texRejillaBlanco.specular  = imgRejillaBlanco.getTexture();
    texRejillaBlanco.emissive  = imgNoEmissive.getTexture();
    texRejillaBlanco.normal    = 0;
    texRejillaBlanco.shininess = 76.8;

    //Textura Rejilla Metal
    texRejillaMetal.diffuse   = imgRejillaMetal.getTexture();
    texRejillaMetal.specular  = imgRejillaMetal.getTexture();
    texRejillaMetal.emissive  = imgNoEmissive.getTexture();
    texRejillaMetal.normal    = 0;
    texRejillaMetal.shininess = 76.8;

    //Textura Metal Negro
    texMetalNegro.diffuse   = imgMetalNegro.getTexture();
    texMetalNegro.specular  = imgMetalNegro.getTexture();
    texMetalNegro.emissive  = imgNoEmissive.getTexture();
    texMetalNegro.normal    = 0;
    texMetalNegro.shininess = 76.8;

    // Material Cristales
    cyan.ambient   = glm::vec4(0.0f,0.1f,0.06f ,0.55);
    cyan.diffuse   = glm::vec4(0.0f,0.50980392f,0.50980392f,0.55);
    cyan.specular  = glm::vec4(0.50196078f,0.50196078f,0.50196078f,0.55);
    cyan.emissive  = glm::vec4(0.000000, 0.000000, 0.000000, 1.00);
    cyan.shininess = 76.8;

    //Textura FibraCarbono
    texFibraCarbono.diffuse   = imgFibraCarbono.getTexture();
    texFibraCarbono.specular  = imgFibraCarbono.getTexture();
    texFibraCarbono.emissive  = imgNoEmissive.getTexture();
    texFibraCarbono.normal    = 0;
    texFibraCarbono.shininess = 76.8;

    //Textura Cuero
    texCueroNegro.diffuse   = imgCueroNegro.getTexture();
    texCueroNegro.specular  = imgCueroNegro.getTexture();
    texCueroNegro.emissive  = imgNoEmissive.getTexture();
    texCueroNegro.normal    = 0;
    texCueroNegro.shininess = 76.8;

    //Textura Cuero Marron
    texCueroMarron.diffuse   = imgCueroMarron.getTexture();
    texCueroMarron.specular  = imgCueroMarron.getTexture();
    texCueroMarron.emissive  = imgNoEmissive.getTexture();
    texCueroMarron.normal    = 0;
    texCueroMarron.shininess = 76.8;

    //Textura Tigre
    texTigre.diffuse   = imgTigre.getTexture();
    texTigre.specular  = imgTigre.getTexture();
    texTigre.emissive  = imgNoEmissive.getTexture();
    texTigre.normal    = 0;
    texTigre.shininess = 26.8;

    //Textura Banco
    texBench.diffuse   = imgBenchColor.getTexture();
    texBench.specular  = imgBenchRugoso.getTexture();
    texBench.emissive  = imgNoEmissive.getTexture();
    texBench.normal    = imgBenchNormal.getTexture();
    texBench.shininess = 26.8;

    //Textura Stop
    texStop.diffuse   = imgStopColor.getTexture();
    texStop.specular  = imgStopRugoso.getTexture();
    texStop.emissive  = imgNoEmissive.getTexture();
    texStop.normal    = imgStopNormal.getTexture();
    texStop.shininess = 76.8;

    //Textura Tronco
    texTronco.diffuse   = imgTroncoColor.getTexture();
    texTronco.specular  = imgTroncoSpecular.getTexture();
    texTronco.emissive  = imgNoEmissive.getTexture();
    texTronco.normal    = imgTroncoNormal.getTexture();
    texTronco.shininess = 26.8;

    //Textura Arbol
    texArbol.diffuse   = imgArbolColor.getTexture();
    texArbol.specular  = imgArbolColor.getTexture();
    texArbol.emissive  = imgNoEmissive.getTexture();
    texArbol.normal    = 0;
    texArbol.shininess = 26.8;

    //Textura Ardilla
    texArdilla.diffuse   = imgArdilla.getTexture();
    texArdilla.specular  = imgArdilla.getTexture();
    texArdilla.emissive  = imgNoEmissive.getTexture();
    texArdilla.normal    = 0;
    texArdilla.shininess = 26.8;

    //Textura Casa
    texCasa.diffuse   = imgCasa.getTexture();
    texCasa.specular  = imgCasa.getTexture();
    texCasa.emissive  = imgNoEmissive.getTexture();
    texCasa.normal    = imgPaisajeModernoNormal.getTexture();
    texCasa.shininess = 26.8;

    //Textura Paisaje Moderno
    texPaisajeModerno.diffuse   = imgPaisajeModerno.getTexture();
    texPaisajeModerno.specular  = imgPaisajeModerno.getTexture();
    texPaisajeModerno.emissive  = imgNoEmissive.getTexture();
    texPaisajeModerno.normal    = imgPaisajeModernoNormal.getTexture();
    texPaisajeModerno.shininess = 26.8;
}

void renderScene() {

    //Control de luces dependiendo de si es de noche o de dia
    if(noche) {
        //Ambiente
        ambiente=0.5;

        direccional=0.0;

        //Luces coches
        delanteraA = 2.0;
        delanteraD = 5.0;
        delanteraS = 2.0;

        traseraA = 1.2;
        traseraD = 2.0;
        traseraS = 1.0;

        lateralA = 1.0;
        lateralAy = 0.5;
        lateralD = 2.0;
        lateralDy = 1.0;
        lateralS = 1.0;
        lateralSy = 0.5;

        //Luces farolas
        farolaA = 12.0;
        farolaD = 12.0;
        farolaS = 10.0;

    }
    else{
        //Ambiente
        ambiente=1;

        direccional=0.8;

        //Luces coches
        delanteraA = 0.0;
        delanteraD = 0.0;
        delanteraS = 0.0;

        traseraA = 0.0;
        traseraD = 0.0;
        traseraS = 0.0;

        lateralA = 0.0;
        lateralAy = 0.0;
        lateralD = 0.0;
        lateralDy = 0.0;
        lateralS = 0.0;
        lateralSy = 0.0;

        //Luces farolas
        farolaA = 0.0;
        farolaD = 0.0;
        farolaS = 0.0;
    }

    //Luz ambiental global
    lightG.ambient = glm::vec3(ambiente, ambiente, ambiente);

    // Luces direccionales
    lightD[0].direction = glm::vec3(-1.0, -10.0, 0.0);
    lightD[0].ambient   = glm::vec3( direccional, direccional, direccional);
    lightD[0].diffuse   = glm::vec3( direccional, direccional, direccional);
    lightD[0].specular  = glm::vec3( direccional, direccional, direccional);

    // LUCES FOCALES
    // Luz Delanteras
    lightF[0].position    = glm::vec3(0,  2,  -1.8);
    lightF[0].direction   = glm::vec3( 4, -1, 0);
    lightF[0].ambient     = glm::vec3( delanteraA,  delanteraA,  delanteraA);
    lightF[0].diffuse     = glm::vec3( delanteraD,  delanteraD,  delanteraD);
    lightF[0].specular    = glm::vec3( delanteraS,  delanteraS,  delanteraS);
    lightF[0].innerCutOff = 12.0;
    lightF[0].outerCutOff = lightF[0].innerCutOff + 7.0;
    lightF[0].c0          = 1.000;
    lightF[0].c1          = 0.090;
    lightF[0].c2          = 0.032;

    lightF[1].position    = glm::vec3( 0,  2.0,  2);
    lightF[1].direction   = glm::vec3(4, -1.0, 0);
    lightF[1].ambient     = glm::vec3( delanteraA,  delanteraA,  delanteraA);
    lightF[1].diffuse     = glm::vec3( delanteraD,  delanteraD,  delanteraD);
    lightF[1].specular    = glm::vec3( delanteraS,  delanteraS,  delanteraS);
    lightF[1].innerCutOff = 12.0;
    lightF[1].outerCutOff = lightF[1].innerCutOff + 7.0;
    lightF[1].c0          = 1.000;
    lightF[1].c1          = 0.090;
    lightF[1].c2          = 0.032;
    // Luz Traseras
    lightF[2].position    = glm::vec3(-15.6,  2,  2.6);
    lightF[2].direction   = glm::vec3( -2, -2, 0);
    lightF[2].ambient     = glm::vec3( traseraA,  0,  0);
    lightF[2].diffuse     = glm::vec3( traseraD,  0,  0);
    lightF[2].specular    = glm::vec3( traseraS,  0,  0);
    lightF[2].innerCutOff = 10.0;
    lightF[2].outerCutOff = lightF[2].innerCutOff + 5.0;
    lightF[2].c0          = 1.000;
    lightF[2].c1          = 0.090;
    lightF[2].c2          = 0.032;

    lightF[3].position    = glm::vec3( -15.6,  2,  -2.3);
    lightF[3].direction   = glm::vec3(-2, -2, 0);
    lightF[3].ambient     = glm::vec3( traseraA,  0,  0);
    lightF[3].diffuse     = glm::vec3( traseraD,  0,  0);
    lightF[3].specular    = glm::vec3( traseraS,  0,  0);
    lightF[3].innerCutOff = 10.0;
    lightF[3].outerCutOff = lightF[3].innerCutOff + 5.0;
    lightF[3].c0          = 1.000;
    lightF[3].c1          = 0.090;
    lightF[3].c2          = 0.032;
    // Luz Laterales
    lightF[4].position    = glm::vec3(-5,  1.75,  3.5);
    lightF[4].direction   = glm::vec3( 0, -1.65, 1.2);
    lightF[4].ambient     = glm::vec3( lateralA,  lateralAy,  0);
    lightF[4].diffuse     = glm::vec3( lateralD,  lateralDy,  0);
    lightF[4].specular    = glm::vec3( lateralS,  lateralSy,  0);
    lightF[4].innerCutOff = 15.0;
    lightF[4].outerCutOff = lightF[4].innerCutOff + 10.0;
    lightF[4].c0          = 1.000;
    lightF[4].c1          = 0.090;
    lightF[4].c2          = 0.032;

    lightF[5].position    = glm::vec3( -5,  1.75,  -3.3);
    lightF[5].direction   = glm::vec3(0, -1.65, -1.2);
    lightF[5].ambient     = glm::vec3( lateralA,  lateralAy,  0);
    lightF[5].diffuse     = glm::vec3( lateralD,  lateralDy,  0);
    lightF[5].specular    = glm::vec3( lateralS,  lateralSy,  0);
    lightF[5].innerCutOff = 15.0;
    lightF[5].outerCutOff = lightF[5].innerCutOff + 10.0;
    lightF[5].c0          = 1.000;
    lightF[5].c1          = 0.090;
    lightF[5].c2          = 0.032;

    // Luces posicionales(FAROLAS)
    lightP[0].position    = glm::vec3(-27+wMov, 8, -18+aMov);
    lightP[0].ambient     = glm::vec3(farolaA, farolaA, farolaA);
    lightP[0].diffuse     = glm::vec3(farolaD, farolaD, farolaD);
    lightP[0].specular    = glm::vec3(farolaS, farolaS, farolaS);
    lightP[0].c0          = 1.00;
    lightP[0].c1          = 0.22;
    lightP[0].c2          = 0.20;

    lightP[1].position    = glm::vec3(14+wMov, 8, -18+aMov);
    lightP[1].ambient     = glm::vec3(farolaA, farolaA, farolaA);
    lightP[1].diffuse     = glm::vec3(farolaD, farolaD, farolaD);
    lightP[1].specular    = glm::vec3(farolaS, farolaS, farolaS);
    lightP[1].c0          = 1.00;
    lightP[1].c1          = 0.22;
    lightP[1].c2          = 0.20;

    lightP[2].position    = glm::vec3(-27+wMov, 8, 31+aMov);
    lightP[2].ambient     = glm::vec3(farolaA, farolaA, farolaA);
    lightP[2].diffuse     = glm::vec3(farolaD, farolaD, farolaD);
    lightP[2].specular    = glm::vec3(farolaS, farolaS, farolaS);
    lightP[2].c0          = 1.00;
    lightP[2].c1          = 0.22;
    lightP[2].c2          = 0.20;

    lightP[3].position    = glm::vec3(14+wMov, 8, 31+aMov);
    lightP[3].ambient     = glm::vec3(farolaA, farolaA, farolaA);
    lightP[3].diffuse     = glm::vec3(farolaD, farolaD, farolaD);
    lightP[3].specular    = glm::vec3(farolaS, farolaS, farolaS);
    lightP[3].c0          = 1.00;
    lightP[3].c1          = 0.22;
    lightP[3].c2          = 0.20;


    // Borramos el buffer de color
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Indicamos los shaders a utilizar
    shaders.useShaders();

    // Matriz P
    float fovy   = valorFovy;
    float nplane =  0.1;
    float fplane = 90.0;
    float aspect = (float)w/(float)h;
    glm::mat4 P = glm::perspective(glm::radians(fovy), aspect, nplane, fplane);

    // Matriz V
    float x;
    float y;
    float z;
    if(camaraCoche){
         x = xEye;
         y = yEye;
         z = zEye;

    }else{
        x = 30.0f*glm::cos(glm::radians(alphaY))*glm::sin(glm::radians(alphaX));
        y = 30.0f*glm::sin(glm::radians(alphaY));
        z = 30.0f*glm::cos(glm::radians(alphaY))*glm::cos(glm::radians(alphaX));
    }
    glm::vec3 eye(x,y,z);
    glm::vec3 center(xCenter, yCenter, zCenter);
    glm::vec3 up    (0.0, 1.0,  0.0);
    glm::mat4 V = glm::lookAt(eye, center, up);

    // Fijamos las luces
    setLights(P,V);

    // Dibujamos la escena
    glm::mat4 S = glm::scale(I, glm::vec3(0.15, 0.15,0.15));
    glm::mat4 T_COCHE = glm::translate(I, glm::vec3(0, -0.68, 0));
    ControlCoche();
    glm::mat4 T_Mov_Escena = glm::translate(I, glm::vec3(wMov, 0, aMov));
    drawCoche(P,V,T_COCHE);
    drawEscena(P,V,T_Mov_Escena);
    MovimientoArdillas();

}

void drawObject(Model model, glm::vec3 color, glm::mat4 P, glm::mat4 V, glm::mat4 M) {

    shaders.setMat4("uPVM",P*V*M);

    glEnable(GL_POLYGON_OFFSET_FILL);
    shaders.setVec3("uColor",color);
    model.renderModel(GL_FILL);
    glDisable(GL_POLYGON_OFFSET_FILL);

    glm::vec3 colorAlambre = glm::vec3(color.r*0.75, color.g*0.75, color.b*0.75);
    shaders.setVec3("uColor",colorAlambre);
    model.renderModel(GL_LINE);

}

void drawObjectMat(Model model, Material material, glm::mat4 P, glm::mat4 V, glm::mat4 M) {

    shaders.setMat4("uN"  ,glm::transpose(glm::inverse(M)));
    shaders.setMat4("uM"  ,M);
    shaders.setMat4("uPVM",P*V*M);
    shaders.setBool("uWithMaterials",true);
    shaders.setMaterial("umaterial",material);
    model.renderModel(GL_FILL);

}

void drawObjectTex(Model model, Textures textures, glm::mat4 P, glm::mat4 V, glm::mat4 M) {

    shaders.setMat4("uN"  ,glm::transpose(glm::inverse(M)));
    shaders.setMat4("uM"  ,M);
    shaders.setMat4("uPVM",P*V*M);
    shaders.setBool("uWithMaterials",false);
    shaders.setTextures("utextures",textures);
    if(textures.normal!=0) shaders.setBool("uWithNormals",true);
    else                   shaders.setBool("uWithNormals",false);
    model.renderModel(GL_FILL);

}

void setLights(glm::mat4 P, glm::mat4 V) {

    shaders.setLight("ulightG",lightG);
    for(int i=0; i<NLD; i++) shaders.setLight("ulightD["+toString(i)+"]",lightD[i]);
    for(int i=0; i<NLP; i++) shaders.setLight("ulightP["+toString(i)+"]",lightP[i]);
    for(int i=0; i<NLF; i++) shaders.setLight("ulightF["+toString(i)+"]",lightF[i]);

    for(int i=0; i<NLP; i++) {
        glm::mat4 M = glm::translate(I,lightP[i].position) * glm::scale(I,glm::vec3(0.3));
        drawObjectMat(sphere, mluz, P, V, M);
    }

    for(int i=0; i<NLF; i++) {
        if(i<2) {
            glm::mat4 M = glm::translate(I, lightF[i].position) * glm::scale(I, glm::vec3(0.2));
            glm::mat4 T = glm::translate(I,glm::vec3(0,1.2,0));
            drawObjectMat(sphere, mluz, P, V, M*T);
        }
        else if(i>=2 && i<4){
            glm::mat4 T = glm::translate(I,glm::vec3(0,1.2,0));
            glm::mat4 M = glm::translate(I, lightF[i].position) * glm::scale(I, glm::vec3(0.1));
            drawObjectTex(cube, texRuby, P, V, M*T);
        }
        else{
            glm::mat4 T = glm::translate(I,glm::vec3(0,1.2,0));
            glm::mat4 M = glm::translate(I, lightF[i].position) * glm::scale(I, glm::vec3(0.07));
            drawObjectTex(cube, texGold, P, V, M*T);
        }
    }
}

void drawCoche(glm::mat4 P, glm::mat4 V, glm::mat4 M){

    //Conjunto de Partes Delanteras del coche
    glm::mat4 T1 = glm::translate(I,glm::vec3(0,2,2));
    drawParteDelanteraCoche(P,V,M*T1);

    // Capo
    capo(P,V,M);

    //Puertas
    drawPuerta(P,V,M);
    parteDeAtrasCoche(P,V,M);
    parteDeAbajoCohe(P,V,M);
    drawParteAtrasMaletero(P,V,M);

    // RUEDAS
    glm::mat4 Rotacion = glm::rotate(I, glm::radians(rotRuedas), glm::vec3(1, 0, 0));
    glm::mat4 S_RUEDA = glm::scale(I, glm::vec3(0.8, 0.8,0.8));
    glm::mat4 R_RUEDA_IZQ = glm::rotate(I, glm::radians(90.0f), glm::vec3(0, 1, 0));
    glm::mat4 R_RUEDA_DRCH = glm::rotate(I, glm::radians(-90.0f), glm::vec3(0, 1, 0));

    // Rueda Delantera Derecha
    glm::mat4 T_RUEDA_DEL_DRCH = glm::translate(I, glm::vec3(-3.15, 1.65, 3.2));
    drawRuedas(P,V,M*T_RUEDA_DEL_DRCH*R_RUEDA_DRCH*Rotacion*S_RUEDA);

    // Rueda Delantera Izquierda
    glm::mat4 T_RUEDA_DEL_IZQ = glm::translate(I, glm::vec3(-3.15, 1.65, -3));
    drawRuedas(P,V,M*T_RUEDA_DEL_IZQ*R_RUEDA_IZQ*Rotacion*S_RUEDA);

    // Rueda Trasera Derecha
    glm::mat4 T_RUEDA_TR_DRCH = glm::translate(I, glm::vec3(-11.65, 1.65, 3.2));
    drawRuedas(P,V,M*T_RUEDA_TR_DRCH*R_RUEDA_DRCH*Rotacion*S_RUEDA);

    // Rueda Trasera Izquierda
    glm::mat4 T_RUEDA_TR_IZQ = glm::translate(I, glm::vec3(-11.65, 1.65, -3));
    drawRuedas(P,V,M*T_RUEDA_TR_IZQ*R_RUEDA_IZQ*Rotacion*S_RUEDA);

    //ASIENTOS
    glm::mat4 S_ASIENTOS     = glm::scale(I, glm::vec3(0.8, 0.7,1));
    glm::mat4 R_ASIENTOS = glm::rotate(I, glm::radians(-90.0f), glm::vec3(0, 1, 0));
    glm::mat4 T_ASIENTOS = glm::translate(I, glm::vec3(-7.3, 1.8, 0.1));
    drawSillaCoche(P,V,M*T_ASIENTOS*R_ASIENTOS*S_ASIENTOS);

    //VOLANTE
    glm::mat4 S_VOLANTE     = glm::scale(I, glm::vec3(0.5, 0.5,0.5));
    glm::mat4 R_VOLANTE = glm::rotate(I, glm::radians(180.0f), glm::vec3(0, 1, 0));
    glm::mat4 T_VOLANTE = glm::translate(I, glm::vec3(-7, 3, -1));
    drawVolante(P,V,M*T_VOLANTE*R_VOLANTE*S_VOLANTE);

    //RETROVISOR
    glm::mat4 S_RETROVISOR     = glm::scale(I, glm::vec3(0.25, 0.2,0.2));
    glm::mat4 R_RETROVISOR = glm::rotate(I, glm::radians(85.0f), glm::vec3(0, 1, 0));
    glm::mat4 T_RETROVISOR = glm::translate(I, glm::vec3(-6, 3, -3));
    drawRetrovisor(P,V,M*T_RETROVISOR*R_RETROVISOR*S_RETROVISOR);

    glm::mat4 R_RETROVISOR2 = glm::rotate(I, glm::radians(-150.0f), glm::vec3(0, 1, 0));
    glm::mat4 T_RETROVISOR2 = glm::translate(I, glm::vec3(-5.7, 3.1, 3.4));
    drawRetrovisor(P,V,M*T_RETROVISOR2*R_RETROVISOR2*S_RETROVISOR);

    //TECHO
    if(techo%2==0) {
        drawTecho(P, V, M);
        //VENTANAS
        drawCristales(P,V,M);
    }

    //PARABRISAS
    drawParabrisas(P,V,M);

    //TUBO DE ESCAPE
    drawTuboEscape(P,V,M);

    //LUCES LATERALES
    glm::mat4 S_LUCES     = glm::scale(I, glm::vec3(0.5, 0.5,0.5));
    glm::mat4 R_LUCES = glm::rotate(I, glm::radians(90.0f), glm::vec3(0, 1, 0));
    glm::mat4 T_LUCES = glm::translate(I, glm::vec3(-5, 2, -3.3));
    drawLucesLaterales(P,V,M*T_LUCES*R_LUCES*S_LUCES);

    glm::mat4 R_LUCES2 = glm::rotate(I, glm::radians(-90.0f), glm::vec3(0, 1, 0));
    glm::mat4 T_LUCES2 = glm::translate(I, glm::vec3(-5, 2, 3.5));
    drawLucesLaterales(P,V,M*T_LUCES2*R_LUCES2*S_LUCES);

    //LUCES TRASERAS(Reutilizamos el modelo de luces laterales)
    glm::mat4 St_LUCES     = glm::scale(I, glm::vec3(0.8, 0.8,0.8));
    glm::mat4 Rt_LUCES = glm::rotate(I, glm::radians(180.0f), glm::vec3(0, 1, 0));
    glm::mat4 Tt_LUCES = glm::translate(I, glm::vec3(-15.6, 2, 2.6));
    drawLucesLaterales(P,V,M*Tt_LUCES*Rt_LUCES*St_LUCES);

    glm::mat4 Tt_LUCES2 = glm::translate(I, glm::vec3(-15.6, 2, -2.3));
    drawLucesLaterales(P,V,M*Tt_LUCES2*Rt_LUCES*St_LUCES);

    //MALETERO
    drawMaletero(P,V,M);

    //INTERIOR MALETERO
    glm::mat4 S_INTERIOR     = glm::scale(I, glm::vec3(0.5, 0.5,0.5));
    glm::mat4 R_INTERIOR = glm::rotate(I, glm::radians(90.0f), glm::vec3(0, 1, 0));
    glm::mat4 R_INTERIOR2 = glm::rotate(I, glm::radians(90.0f), glm::vec3(0, 0, 1));
    glm::mat4 T_INTERIOR = glm::translate(I, glm::vec3(-14, 2, 0));
    drawObjectTex(prueba, texMetal, P, V, M*T_INTERIOR*R_INTERIOR2*R_INTERIOR*S_INTERIOR);

    marcoCristalDelantero(P,V,M);

}
void drawParachoques(glm::mat4 P, glm::mat4 V, glm::mat4 M){

    //Barra horizontal Izquieda
    glm::mat4 T = glm::translate(I,glm::vec3(-0.15,1,1));
    glm::mat4 S = glm::scale(I,glm::vec3(-0.05,0.1,0.9));
    drawObjectTex(cube,texMetal,P,V,M*T*S);

    //Barra inclinada izquieda
    glm::mat4 T1 = glm::translate(I,glm::vec3(0.2,1,-0.5));
    glm::mat4 S1 = glm::scale(I,glm::vec3(0.05,0.1,0.7));
    glm::mat4 R = glm::rotate(I, glm::radians(-30.0f), glm::vec3(0, 1, 0));
    drawObjectTex(cube,texMetal,P,V,M*T1*R*S1);

    //Barra inclinada derecha
    glm::mat4 T2 = glm::translate(I,glm::vec3(0.2,1,-1.65));
    glm::mat4 R2 = glm::rotate(I, glm::radians(30.0f), glm::vec3(0, 1, 0));
    drawObjectTex(cube,texMetal,P,V,M*T2*R2*S1);

    //Barra horizontal derecha
    glm::mat4 T3 = glm::translate(I,glm::vec3(-0.15,1,-3.15));
    drawObjectTex(cube,texMetal,P,V,M*T3*S);

    //bloques azules
    glm::mat4 Tc = glm::translate(I,glm::vec3(-0.45,1,1));
    glm::mat4 Sc = glm::scale(I,glm::vec3(-0.25,0.1,0.9));
    drawObjectTex(cube,texRuby,P,V,M*Tc*Sc);

    glm::mat4 Tc2 = glm::translate(I,glm::vec3(-0.45,1,-3.15));
    drawObjectTex(cube,texRuby,P,V,M*Tc2*Sc);

    glm::mat4 Tl = glm::translate(I,glm::vec3(-0.3,1,-0.7));
    glm::mat4 Sl = glm::scale(I,glm::vec3(0.5,0.1,0.7));
    drawObjectTex(cube,texRuby,P,V,M*Tl*R*Sl);

    glm::mat4 Tl2 = glm::translate(I,glm::vec3(-0.3,1,-1.45));
    drawObjectTex(cube,texRuby,P,V,M*Tl2*R2*Sl);
}
void drawParteDelanteraCoche(glm::mat4 P,glm::mat4 V,glm::mat4 M){

    glm::mat4 Sluces = glm::scale(I,glm::vec3(0.8,0.8,0.8));

    //Luces Delanteras Izquierda
    glm::mat4 Tizquierda = glm::translate(I,glm::vec3(0.05,0.2,0));
    drawLucesDelanteras(P,V,M*Tizquierda*Sluces);

    //Luces Delanteras Dechera
    glm::mat4 Tderecha = glm::translate(I,glm::vec3(0.05,0.2,-3.8));
    drawLucesDelanteras(P,V,M*Tderecha*Sluces);

    //Infraestructura delantera del coche
    infraestructuraDelanteCoche(P,V,M);

    glm::mat4 Tparachoques = glm::translate(I,glm::vec3(0.5,-0.5,-0.842));
    drawParachoques(P,V,M*Tparachoques);

}
void infraestructuraDelanteCoche(glm::mat4 P,glm::mat4 V,glm::mat4 M){

    //Placa de luz izquierda
    glm::mat4 T = glm::translate(I,glm::vec3(0,1,0));
    glm::mat4 S = glm::scale(I,glm::vec3(0.05,0.4,0.7));
    drawObjectTex(cube,texRuby,P,V,M*T*S);

    //PaloLateralIzquierdo
    glm::mat4 S1 = glm::scale(I,glm::vec3(0.4,0.8,0.1));
    glm::mat4 T1 = glm::translate(I,glm::vec3(0.1,0.7,0.8));
    drawObjectTex(cube,texMetal,P,V,M*T1*S1);

    //PaloVerde medio 1
    glm::mat4 S2 = glm::scale(I,glm::vec3(0.1,0.6,0.1));
    glm::mat4 T2 = glm::translate(I,glm::vec3(0.1,1.2,-0.8));
    drawObjectTex(cube,texMetal,P,V,M*T2*S2);

    //Panel de lado1
    glm::mat4 R = glm::rotate(I, glm::radians(-30.0f), glm::vec3(0, 1, 0));
    glm::mat4 T3 = glm::translate(I,glm::vec3(0.5,1.1,-1.32));
    glm::mat4 S3 = glm::scale(I,glm::vec3(0.05,0.6,0.7));
    drawObjectTex(cube,texRejillaMetal,P,V,M*T3*R*S3);

    //Panel de lado2
    glm::mat4 R2 = glm::rotate(I, glm::radians(30.0f), glm::vec3(0, 1, 0));
    glm::mat4 T4 = glm::translate(I,glm::vec3(0.5,1.1,-2.49));
    drawObjectTex(cube,texRejillaMetal,P,V,M*T4*R2*S3);

    //Palo verde medio 2
    glm::mat4 T5 = glm::translate(I,glm::vec3(0.1,1.2,-3));
    drawObjectTex(cube,texMetal,P,V,M*T5*S2);

    //Placa de luz derecho
    glm::mat4 T6 = glm::translate(I,glm::vec3(0,1,-3.8));
    drawObjectTex(cube,texRuby,P,V,M*T6*S);

    //PaloLateralDerecho
    glm::mat4 T7 = glm::translate(I,glm::vec3(0.1,0.7,-4.6));
    drawObjectTex(cube,texMetal,P,V,M*T7*S1);

    //Panel luz de abajo izquierdo
    glm::mat4 Sinferior = glm::scale(I,glm::vec3(0.05,0.25,0.7));
    glm::mat4 Tinferior = glm::translate(I,glm::vec3(0,0.2,0));
    drawObjectTex(cube,texMetal,P,V,M*Tinferior*Sinferior);

    glm::mat4 Sinferior1 = glm::scale(I,glm::vec3(0.05,0.25,1.25));
    glm::mat4 Tinferior1 = glm::translate(I,glm::vec3(0.1,0.2,-1.9));
    drawObjectTex(cube,texRuby,P,V,M*Tinferior1*Sinferior1);

    //panel luz de abajo derecha
    glm::mat4 Tinferior2 = glm::translate(I,glm::vec3(0,0.2,-3.8));
    drawObjectTex(cube,texMetal,P,V,M*Tinferior2*Sinferior);


    //luz abajo derecho
    glm::mat4 Sluzinf = glm::scale(I,glm::vec3(0.1,0.1,0.4));
    drawObjectTex(cube,texMetalNegro,P,V,M*Tinferior2*Sluzinf);

    drawObjectTex(cube,texMetalNegro,P,V,M*Tinferior*Sluzinf);

    //Tope delantero interior
    glm::mat4 Stope = glm::scale(I,glm::vec3(0.9,1,2));
    glm::mat4 Rtope = glm::rotate(I, glm::radians(110.0f), glm::vec3(0, 0, 1));
    glm::mat4 Ttope = glm::translate(I,glm::vec3(-5.4,0.58,-0.8));

    glm::mat4 Rtope1 = glm::rotate(I, glm::radians(-3.0f), glm::vec3(0, 1, 0));
    drawObjectTex(plane,texMetal,P,V,M*Ttope*Rtope1*Rtope*Stope);

    glm::mat4 Ttope2 = glm::translate(I,glm::vec3(-5.4,0.58,-3));
    glm::mat4 Rtope2 = glm::rotate(I, glm::radians(3.0f), glm::vec3(0, 1, 0));
    drawObjectTex(plane,texMetal,P,V,M*Ttope2*Rtope2*Rtope*Stope);

}
void drawSillaCoche(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    drawAsientoDelantero(P,V,M);
    glm::mat4 T = glm::translate(I,glm::vec3(0,0,3));
    drawAsientoTrasero(P,V,M*T);
}
void capo(glm::mat4 P, glm::mat4 V, glm::mat4 M){

    //cilindro capo lado izquierdo
    glm::mat4 T = glm::translate(I,glm::vec3(-2.7,3.4,2));
    glm::mat4 S = glm::scale(I,glm::vec3(0.1,2.9,0.7));
    glm::mat4 R = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,0,1));
    drawObjectTex(cylinder,texRuby,P,V,M*T*R*S);

    //cilindro capo lado derecho
    glm::mat4 T1 = glm::translate(I,glm::vec3(-2.7,3.4,-1.8));
    drawObjectTex(cylinder,texRuby,P,V,M*T1*R*S);

    //cilindro lateral capo izquierdo
    glm::mat4 S1 = glm::scale(I,glm::vec3(0.2,2,0.2));
    glm::mat4 T2 = glm::translate(I,glm::vec3(-2.4,3.5,2.8));
    drawObjectTex(cylinder,texRuby,P,V,M*T2*R*S1);

    //cilindro lateral capo derecho
    glm::mat4 T3 = glm::translate(I,glm::vec3(-2.4,3.5,-2.6));
    drawObjectTex(cylinder,texRuby,P,V,M*T3*R*S1);

    //componente del medio formado por dos triangulos y 2 cilindros

    //triangulo izquierdo
    glm::mat4 T4 = glm::translate(I,glm::vec3(0.2,3.72,0.7));
    glm::mat4 R2x = glm::rotate(I,glm::radians(90.0f), glm::vec3(1,0,0));
    glm::mat4 R2z = glm::rotate(I,glm::radians(-1.0f), glm::vec3(0,0,1));
    glm::mat4 S2 = glm::scale(I,glm::vec3(0.7,0.6,1.5));
    drawObjectTex(triangle,texRuby,P,V,M*T4*R2x*R2z*S2);
    //triangulo derecho
    glm::mat4 R2z2 = glm::rotate(I,glm::radians(-60.0f), glm::vec3(0,0,1));
    glm::mat4 T5 = glm::translate(I,glm::vec3(0.35,3.72,-0.2));
    drawObjectTex(triangle,texRuby,P,V,M*T5*R2x*R2z2*S2);
    //cilindro de en medio
    glm::mat4 T6 = glm::translate(I,glm::vec3(-2.8,3.5,0.15));
    glm::mat4 S3 = glm::scale(I,glm::vec3(0.3,3,0.7));
    drawObjectTex(cylinder,texRuby,P,V,M*T6*R*S3);

    //cilindro inclinado izquierdo
    glm::mat4 S4 = glm::scale(I,glm::vec3(0.1,3,0.7));
    glm::mat4 T7 = glm::translate(I,glm::vec3(-2.8,3.5,1.2));
    glm::mat4 R3 = glm::rotate(I,glm::radians(-15.0f),glm::vec3(0,1,0));
    drawObjectTex(cylinder,texRuby,P,V,M*T7*R*R3*S4);


    //cilindro inclinado derecho
    glm::mat4 T8 = glm::translate(I,glm::vec3(-2.8,3.5,-1));
    glm::mat4 R4 = glm::rotate(I,glm::radians(15.0f),glm::vec3(0,1,0));
    drawObjectTex(cylinder,texRuby,P,V,M*T8*R*R4*S4);

    //detalle capo medio
    glm::mat4 T9  = glm::translate(I,glm::vec3(-2.8,3.8,0.15));
    glm::mat4 S5 = glm::scale(I,glm::vec3(0.05,2.6,0.05));
    drawObjectTex(cylinder,texMetal,P,V,M*T9*R*S5);

    glm::mat4 T10 = glm::translate(I,glm::vec3(-0.5,3.8,0.15));
    glm::mat4 Slogo = glm::scale(I,glm::vec3(0.1,0.1,0.1));
    logoCoche(P,V,M*T10*Slogo);

    lateralIzquierdoCoche(P,V,M);
    lateralDerechoCoche(P,V,M);
}
void logoCoche(glm::mat4 P,glm::mat4 V, glm::mat4 M){
    //logo coche
    glm::mat4 T10 = glm::translate(I,glm::vec3(-0.5,1,0));
    glm::mat4 Slogo = glm::scale(I,glm::vec3(0.5,0.5,0.5));
    drawObjectTex(cone,texMetal,P,V,M*T10*Slogo);

    glm::mat4 T11 = glm::translate(I,glm::vec3(-0.5,2.8,0));
    glm::mat4 Slogo2 = glm::scale(I,glm::vec3(1,1,1));
    glm::mat4 Rlogo = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,0,1));
    drawObjectTex(torus,texMetal,P,V,M*T11*Rlogo*Slogo2);
}
void marcoCristalDelantero(glm::mat4 P,glm::mat4 V,glm::mat4 M){

    //barra amarilla izquierda
    glm::mat4 S = glm::scale(I,glm::vec3(0.1,0.1,1.5));
    glm::mat4 R = glm::rotate(I,glm::radians(10.0f),glm::vec3(1,0,0));
    glm::mat4 T = glm::translate(I,glm::vec3(-5.7,3.5,1.7));
    drawObjectTex(cube,texRuby,P,V,M*T*R*S);


    //barra amarilla derecha
    glm::mat4 R2 = glm::rotate(I,glm::radians(-10.0f),glm::vec3(1,0,0));
    glm::mat4 T2 = glm::translate(I,glm::vec3(-5.7,3.5,-1.5));
    drawObjectTex(cube,texRuby,P,V,M*T2*R2*S);

    //soporte izquierdo
    glm::mat4 R3 = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,1,0));
    glm::mat4 R4 = glm::rotate(I,glm::radians(30.0f),glm::vec3(0,0,1));
    glm::mat4 S2 = glm::scale(I,glm::vec3(0.05,1.2,0.2));
    glm::mat4 T3 = glm::translate(I,glm::vec3(-6.1,4,3.1));
    drawObjectTex(cylinder,texMetal,P,V,M*T3*R4*R3*S2);

    //soporte derecho
    glm::mat4 T4 = glm::translate(I,glm::vec3(-6.1,4,-2.9));
    drawObjectTex(cylinder,texMetal,P,V,M*T4*R4*R3*S2);

    //inclinado arriba izquierda
    glm::mat4 T5 = glm::translate(I,glm::vec3(-6.7,5.3,1.6));
    glm::mat4 R5 = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,1,0));
    glm::mat4 R6 = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,0,1));
    glm::mat4 R7 = glm::rotate(I,glm::radians(10.0f),glm::vec3(1,0,0));
    glm::mat4 S3 = glm::scale(I,glm::vec3(0.05,1.55,0.2));
    drawObjectTex(cylinder,texMetal,P,V,M*T5*R7*R5*R6*S3);


    //inclinado arriba derecha
    glm::mat4 R8 = glm::rotate(I,glm::radians(-10.0f),glm::vec3(1,0,0));
    glm::mat4 T6 = glm::translate(I,glm::vec3(-6.7,5.3,-1.4));
    drawObjectTex(cylinder,texMetal,P,V,M*T6*R8*R5*R6*S3);
}
void drawPuerta(glm::mat4 P, glm::mat4 V,glm::mat4 M){

    //Apertura de la puerta derecha
    glm::mat4 RotacionDer = glm::rotate(I,glm::radians(-rotPuerta),glm::vec3(0,1,0));
    glm::mat4 T_der = glm::translate(I,glm::vec3(trasPuertax,0,-trasPuertaz));

    //Apertura de la puerta iquierda
    glm::mat4 RotacionIzq = glm::rotate(I,glm::radians(rotPuerta),glm::vec3(0,1,0));
    glm::mat4 T_izq = glm::translate(I,glm::vec3(trasPuertax,0,trasPuertaz));

    //Puerta izquierda
    glm::mat4 S = glm::scale(I,glm::vec3(1,1.5,0.1));
    glm::mat4 R = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,0,1));
    glm::mat4 T = glm::translate(I,glm::vec3(-7.5,2.5,3.3));
    drawObjectTex(cylinder,texRuby,P,V,M*T_izq*T*RotacionIzq*R*S);

    //Puerta derecha
    glm::mat4 T2 = glm::translate(I,glm::vec3(-7.5,2.5,-3.1));
    drawObjectTex(cylinder,texRuby,P,V,M*T_der*T2*RotacionDer*R*S);

    //manillar izquierdo
    glm::mat4 RotacionManIzq = glm::rotate(I,glm::radians(rotPuerta/4),glm::vec3(0,1,0));
    glm::mat4 TManIzq = glm::translate(I,glm::vec3(-trasPuertax/2,0,0));
    manillar(P,V,M*TManIzq*RotacionManIzq);
    //manillar derecho
    glm::mat4 RotacionManDer = glm::rotate(I,glm::radians(-rotPuerta/4),glm::vec3(0,1,0));
    glm::mat4 TManDer = glm::translate(I,glm::vec3(-trasPuertax/2,0,0));
    manillarDerecho(P,V,M*TManDer*RotacionManDer);
}
void lateralIzquierdoCoche(glm::mat4 P,glm::mat4 V,glm::mat4 M){
    glm::mat4 T = glm::translate(I,glm::vec3(-1.3,2.6,2.8));
    glm::mat4 Rz = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,0,1));
    glm::mat4 Rx = glm::rotate(I,glm::radians(90.0f),glm::vec3(1,0,0));
    glm::mat4 S = glm::scale(I,glm::vec3(0.6,1,0.7));
    drawObjectTex(cylinder,texRuby,P,V,M*T*Rx*Rz*S);

    glm::mat4 Scubo = glm::scale(I,glm::vec3(1,0.7,0.05));
    glm::mat4 Tcubo = glm::translate(I,glm::vec3(-3,2.6,2.4));
    drawObjectTex(cube,texRuby,P,V,M*Tcubo*Scubo);

    glm::mat4 S2 = glm::scale(I,glm::vec3(0.6,2.55,0.4));
    glm::mat4 T2 = glm::translate(I,glm::vec3(-2.95,3,2.8));
    drawObjectTex(cylinder,texRuby,P,V,M*T2*Rx*Rz*S2);
}
void lateralDerechoCoche(glm::mat4 P,glm::mat4 V,glm::mat4 M){
    glm::mat4 T = glm::translate(I,glm::vec3(-1.3,2.6,-2.6));
    glm::mat4 Rz = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,0,1));
    glm::mat4 Rx = glm::rotate(I,glm::radians(90.0f),glm::vec3(1,0,0));
    glm::mat4 S = glm::scale(I,glm::vec3(0.6,1,0.7));
    drawObjectTex(cylinder,texRuby,P,V,M*T*Rx*Rz*S);

    glm::mat4 Scubo = glm::scale(I,glm::vec3(1,0.7,0.05));
    glm::mat4 Tcubo = glm::translate(I,glm::vec3(-3,2.6,-2.4));
    drawObjectTex(cube,texRuby,P,V,M*Tcubo*Scubo);

    glm::mat4 S2 = glm::scale(I,glm::vec3(0.6,2.55,0.4));
    glm::mat4 T2 = glm::translate(I,glm::vec3(-2.95,3,-2.6));
    drawObjectTex(cylinder,texRuby,P,V,M*T2*Rx*Rz*S2);
}
void drawVolante(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 R = glm::rotate(I, glm::radians(45.0f), glm::vec3(1, 0, 1));
    volante(P,V,M*R);
}
void volante(glm::mat4 P, glm::mat4 V, glm::mat4 M){

    glm::mat4 Rotacion = glm::rotate(I, glm::radians(rotVolante), glm::vec3(0, 1, 0));
    //circulo hueco
    glm::mat4 Ty = glm::translate(I, glm::vec3(0, 1.5, 0));
    glm::mat4 R = glm::rotate(I, glm::radians(90.0f), glm::vec3(0, 0, 1));
    drawObjectTex(torus, texFibraCarbono, P, V, M*Ty*R*Rotacion);

    //cuadrado
    glm::mat4 Txz = glm::translate(I, glm::vec3(-1, 0, 0));
    glm::mat4 S = glm::scale(I, glm::vec3(0.3, 0.3,0.3));
    drawObjectTex(cube,texMetalNegro, P, V, M*Ty*Txz*R*S);

    //cilindro de enganche
    glm::mat4 T_x = glm::translate(I,glm::vec3(-1.2, 0, 0));
    glm::mat4 Sc = glm::scale(I, glm::vec3(0.1, 1,0.1));
    drawObjectTex(cylinder,texMetal,P,V,M*Ty*Txz*T_x*R*Sc);

    //cilindro
    glm::mat4 Scp = glm::scale(I, glm::vec3(0.1, 0.5,0.1));
    glm::mat4 Tc = glm::translate(I,glm::vec3(-0.5, 0.5, -0.50));
    glm::mat4 R45 = glm::rotate(I, glm::radians(45.0f), glm::vec3(1, 0, 1));
    drawObjectTex(cylinder,texMetal,P,V,M*Ty*Tc*R*R45*Scp);

    glm::mat4 R45m = glm::rotate(I, glm::radians(45.0f), glm::vec3(-1, 0, 1));
    glm::mat4 Tc1 = glm::translate(I,glm::vec3(-0.5, 0.5, 0.5));
    drawObjectTex(cylinder,texMetal,P,V,M*Ty*Tc1*R*R45m*Scp);

    glm::mat4 R45zm = glm::rotate(I, glm::radians(45.0f), glm::vec3(1, 0, -1));
    glm::mat4 Tc2 = glm::translate(I,glm::vec3(-0.5, -0.5, -0.5));
    drawObjectTex(cylinder,texMetal,P,V,M*Ty*Tc2*R*R45zm*Scp);

    glm::mat4 R45zm2 = glm::rotate(I, glm::radians(45.0f), glm::vec3(-1, 0, -1));
    glm::mat4 Tc3 = glm::translate(I,glm::vec3(-0.5, -0.5, 0.5));
    drawObjectTex(cylinder,texMetal,P,V,M*Ty*Tc3*R*R45zm2*Scp);
}
void parteDeAtrasCoche(glm::mat4 P,glm::mat4 V, glm::mat4 M){

    //FONDO LLANTA
    glm::mat4 SLL = glm::scale(I,glm::vec3(1,0.1,0.5));
    glm::mat4 RLL = glm::rotate(I,glm::radians(90.0f),glm::vec3(1,0,0));
    glm::mat4 TLL = glm::translate(I,glm::vec3(-11.6,2.3,3.2));
    drawObjectTex(plane,texRuby,P,V,M*TLL*RLL*SLL);

    glm::mat4 TLL1 = glm::translate(I,glm::vec3(-11.6,2.3,-3));
    drawObjectTex(plane,texRuby,P,V,M*TLL1*RLL*SLL);

    glm::mat4 TLL2 = glm::translate(I,glm::vec3(-3.2,2.3,3.2));
    drawObjectTex(plane,texRuby,P,V,M*TLL2*RLL*SLL);

    glm::mat4 TLL3 = glm::translate(I,glm::vec3(-3.2,2.3,-3));
    drawObjectTex(plane,texRuby,P,V,M*TLL3*RLL*SLL);
}
void parteDeAbajoCohe(glm::mat4 P,glm::mat4 V,glm::mat4 M){
    glm::mat4 S = glm::scale(I,glm::vec3(1.3,0.1,3));
    glm::mat4 T = glm::translate(I,glm::vec3(-0.8,1.85,0.1));
    drawObjectTex(cube,texMetal,P,V,M*T*S);

    glm::mat4 S2 = glm::scale(I,glm::vec3(3.4,0.1,3.2));
    glm::mat4 T2 = glm::translate(I,glm::vec3(-7.35,1.85,0.1));
    drawObjectTex(cube,texMetal,P,V,M*T2*S2);

    glm::mat4 S3 = glm::scale(I,glm::vec3(1.3,0.1,2.8));
    glm::mat4 T3 = glm::translate(I,glm::vec3(-12,1.85,0));
    drawObjectTex(cube,texMetal,P,V,M*T3*S3);

    glm::mat4 S4 = glm::scale(I,glm::vec3(1.3,0.1,2.7));
    glm::mat4 T4 = glm::translate(I,glm::vec3(-3,1.85,0.1));
    drawObjectTex(cube,texMetal,P,V,M*T4*S4);
}
void manillar(glm::mat4 P,glm::mat4 V,glm::mat4 M){

    //Base del manillar
    glm::mat4 S = glm::scale(I,glm::vec3(0.1,0.05,0.05));
    glm::mat4 T = glm::translate(I,glm::vec3(-8,2.9,3.35));
    drawObjectTex(sphere,texMetal,P,V,M*T*S);

    //Cilindro que une la base y el mango
    glm::mat4 R = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,0,1));
    glm::mat4 R2 = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,1,0));
    glm::mat4 S2 = glm::scale(I,glm::vec3(0.05,0.1,0.05));
    glm::mat4 T2 = glm::translate(I,glm::vec3(-7.85,2.9,3.5));
    drawObjectTex(cylinder,texMetal,P,V,M*T2*R2*R*S2);

    //Mango
    glm::mat4 S3 = glm::scale(I,glm::vec3(0.04,0.2,0.04));
    glm::mat4 T3 = glm::translate(I,glm::vec3(-8,2.9,3.6));
    drawObjectTex(cylinder,texMetal,P,V,M*T3*R*S3);


}
void manillarDerecho(glm::mat4 P,glm::mat4 V,glm::mat4 M){
    //Base del manillar
    glm::mat4 S = glm::scale(I,glm::vec3(0.1,0.05,0.05));
    glm::mat4 T = glm::translate(I,glm::vec3(-8,2.9,-3.2));
    drawObjectTex(sphere,texMetal,P,V,M*T*S);

    //Cilindro que une la base y el mango
    glm::mat4 R = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,0,1));
    glm::mat4 R2 = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,1,0));
    glm::mat4 S2 = glm::scale(I,glm::vec3(0.05,0.1,0.05));
    glm::mat4 T2 = glm::translate(I,glm::vec3(-7.85,2.9,-3.3));
    drawObjectTex(cylinder,texMetal,P,V,M*T2*R2*R*S2);

    //Mango
    glm::mat4 S3 = glm::scale(I,glm::vec3(0.04,0.2,0.04));
    glm::mat4 T3 = glm::translate(I,glm::vec3(-8,2.9,-3.4));
    drawObjectTex(cylinder,texMetal,P,V,M*T3*R*S3);
}
void drawLucesLaterales(glm::mat4 P, glm::mat4 V, glm::mat4 M){

    glm::mat4 S = glm::scale(I, glm::vec3(0.05, 0.2,0.4));
    glm::mat4 T = glm::translate(I,glm::vec3(0,1,0));
    drawObject(cube,glm::vec3(1,1,0),P,V,M*T*S);

    glm::mat4 S2 = glm::scale(I, glm::vec3(0.05, 0.1,0.2));
    glm::mat4 T2 = glm::translate(I,glm::vec3(0.05,0,0.15));
    drawObject(cube,glm::vec3(1,1,1),P,V,M*T*T2*S2);

    glm::mat4 T3 = glm::translate(I,glm::vec3(0.05,0,-0.25));
    glm::mat4 S3 = glm::scale(I, glm::vec3(0.05, 0.1,0.1));
    drawObject(cube,glm::vec3(0,0,0),P,V,M*T*T3*S3);

    glm::mat4 S4 = glm::scale(I,glm::vec3(0.05,0.15,0.37));
    glm::mat4 Tx = glm::translate(I,glm::vec3(0.005,0,0));
    drawObject(cube,glm::vec3(1,0,0),P,V,M*T*Tx*S4);
}
void drawLucesDelanteras(glm::mat4 P, glm::mat4 V, glm::mat4 M){

    glm::mat4 S = glm::scale(I, glm::vec3(0.05, 0.4,0.8));
    glm::mat4 T = glm::translate(I,glm::vec3(0,1,0));
    drawObjectTex(cube,texMetal,P,V,M*T*S);

    glm::mat4 S1 = glm::scale(I, glm::vec3(0.05, 0.34,0.35));
    glm::mat4 T1 = glm::translate(I,glm::vec3(0.05,1,0.4));
    drawObjectTex(cube,texMetal,P,V,M*T1*S1);

    glm::mat4 S2 = glm::scale(I, glm::vec3(0.05, 0.34,0.35));
    glm::mat4 T2 = glm::translate(I,glm::vec3(0.05,1,-0.4));
    drawObjectTex(cube,texMetal,P,V,M*T2*S2);

}
void drawParteAtrasMaletero(glm::mat4 P,glm::mat4 V,glm::mat4 M){

    //CILINDROS ROJOS LATERALES
    glm::mat4 S_1 = glm::scale(I,glm::vec3(1,1.5,0.15));
    glm::mat4 T_11 = glm::translate(I,glm::vec3(-14.2,2.5,3.3));
    glm::mat4 R = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,0,1));
    drawObjectTex(cylinder,texRuby,P,V,M*T_11*R*S_1);

    glm::mat4 T_12 = glm::translate(I,glm::vec3(-14.2,2.5,-3.1));
    drawObjectTex(cylinder,texRuby,P,V,M*T_12*R*S_1);

    glm::mat4 S_2 = glm::scale(I,glm::vec3(1,0.9,0.15));
    glm::mat4 T_21 = glm::translate(I,glm::vec3(-9.7,2.5,3.3));
    drawObjectTex(cylinder,texRuby,P,V,M*T_21*R*S_2);

    glm::mat4 T_22 = glm::translate(I,glm::vec3(-9.7,2.5,-3.1));
    drawObjectTex(cylinder,texRuby,P,V,M*T_22*R*S_2);

    glm::mat4 T_31 = glm::translate(I,glm::vec3(-5.1,2.5,3.3));
    drawObjectTex(cylinder,texRuby,P,V,M*T_31*R*S_2);

    glm::mat4 T_32 = glm::translate(I,glm::vec3(-5.1,2.5,-3.1));
    drawObjectTex(cylinder,texRuby,P,V,M*T_32*R*S_2);

    glm::mat4 S_3 = glm::scale(I,glm::vec3(1,1,0.15));
    glm::mat4 T_41 = glm::translate(I,glm::vec3(-1.1,2.5,3.3));
    drawObjectTex(cylinder,texRuby,P,V,M*T_41*R*S_3);

    glm::mat4 T_42 = glm::translate(I,glm::vec3(-1.1,2.5,-3.1));
    drawObjectTex(cylinder,texRuby,P,V,M*T_42*R*S_3);


    glm::mat4 S_4 = glm::scale(I,glm::vec3(0.43,1.2,0.15));
    glm::mat4 T_51 = glm::translate(I,glm::vec3(-3.1,3.07,3.3));
    drawObjectTex(cylinder,texRuby,P,V,M*T_51*R*S_4);

    glm::mat4 T_52 = glm::translate(I,glm::vec3(-3.1,3.07,-3.1));
    drawObjectTex(cylinder,texRuby,P,V,M*T_52*R*S_4);

    glm::mat4 T_61 = glm::translate(I,glm::vec3(-11.65,3.07,3.3));
    drawObjectTex(cylinder,texRuby,P,V,M*T_61*R*S_4);

    glm::mat4 T_62 = glm::translate(I,glm::vec3(-11.65,3.07,-3.1));
    drawObjectTex(cylinder,texRuby,P,V,M*T_62*R*S_4);

    //Triangulos
    glm::mat4 St = glm::scale(I,glm::vec3(0.5,0.3,0.5));
    glm::mat4 Rt = glm::rotate(I,glm::radians(45.0f),glm::vec3(0,0,1));
    glm::mat4 Tt1 = glm::translate(I,glm::vec3(-4.1,2.85,3.45));
    drawObjectTex(triangle,texRuby,P,V,M*Tt1*Rt*St);

    glm::mat4 Tt1_2 = glm::translate(I,glm::vec3(-4.1,2.85,-3.25));
    drawObjectTex(triangle,texRuby,P,V,M*Tt1_2*Rt*St);

    glm::mat4 Tt2 = glm::translate(I,glm::vec3(-12.6,2.85,3.45));
    drawObjectTex(triangle,texRuby,P,V,M*Tt2*Rt*St);

    glm::mat4 Tt2_2 = glm::translate(I,glm::vec3(-12.6,2.85,-3.25));
    drawObjectTex(triangle,texRuby,P,V,M*Tt2_2*Rt*St);

    glm::mat4 Rt2 = glm::rotate(I,glm::radians(-45.0f),glm::vec3(0,0,1));
    glm::mat4 Tt3 = glm::translate(I,glm::vec3(-2.2,2.85,3.45));
    drawObjectTex(triangle,texRuby,P,V,M*Tt3*Rt2*St);

    glm::mat4 Tt3_2 = glm::translate(I,glm::vec3(-2.2,2.85,-3.25));
    drawObjectTex(triangle,texRuby,P,V,M*Tt3_2*Rt2*St);

    glm::mat4 Tt4 = glm::translate(I,glm::vec3(-10.7,2.85,3.45));
    drawObjectTex(triangle,texRuby,P,V,M*Tt4*Rt2*St);

    glm::mat4 Tt4_2 = glm::translate(I,glm::vec3(-10.7,2.85,-3.25));
    drawObjectTex(triangle,texRuby,P,V,M*Tt4_2*Rt2*St);

    glm::mat4 S2 = glm::scale(I,glm::vec3(0.15,0.2,3.3));
    glm::mat4 T3 = glm::translate(I,glm::vec3(-15,1.7,0.2));
    drawObjectTex(cylinder,texRuby,P,V,M*T3*R*S2);

    glm::mat4 S3 = glm::scale(I,glm::vec3(1.6,0.15,3.1));
    glm::mat4 T4 = glm::translate(I,glm::vec3(-14.1,1.9,0.1));
    drawObjectTex(cube,texRuby,P,V,M*T4*S3);

    glm::mat4 S4 = glm::scale(I,glm::vec3(0.15,0.3,1.1));
    glm::mat4 T5 = glm::translate(I,glm::vec3(-15.4,2.3,2.1));
    glm::mat4 R20z = glm::rotate(I,glm::radians(-20.0f),glm::vec3(0,0,1));
    drawObjectTex(cube,texRuby,P,V,M*T5*R20z*S4);

    glm::mat4 T6 = glm::translate(I,glm::vec3(-15.4,2.3,-1.9));
    drawObjectTex(cube,texRuby,P,V,M*T6*R20z*S4);

    glm::mat4 Sm = glm::scale(I,glm::vec3(0.6,0.05,3.2));
    glm::mat4 Rm = glm::rotate(I,glm::radians(5.0f),glm::vec3(0,0,1));
    glm::mat4 Tm = glm::translate(I,glm::vec3(-12.4,3.3,0.1));
    drawObjectTex(cube,texMetal,P,V,M*Tm*Rm*Sm);

    //Ineterior maletero
    glm::mat4 S5_1 = glm::scale(I,glm::vec3(0.05,0.3,3.1));
    glm::mat4 T7_1 = glm::translate(I,glm::vec3(-15.2,2.3,0.2));
    drawObjectTex(cube,texMetalNegro,P,V,M*T7_1*R20z*S5_1);

    glm::mat4 S5_2 = glm::scale(I,glm::vec3(0.05,0.8,3.1));
    glm::mat4 T7_2 = glm::translate(I,glm::vec3(-13.1,2.6,0.2));
    drawObjectTex(cube,texMetalNegro,P,V,M*T7_2*S5_2);

    //Partes de metal del maletero
    glm::mat4 S5 = glm::scale(I,glm::vec3(0.05,0.3,1.1));
    glm::mat4 T7 = glm::translate(I,glm::vec3(-15.3,2.3,0.2));
    drawObjectTex(cube,texMetal,P,V,M*T7*R20z*S5);


    glm::mat4 S6 = glm::scale(I,glm::vec3(0.03,3,0.03));
    glm::mat4 R90z = glm::rotate(I,glm::radians(90.0f),glm::vec3(1,0,0));
    glm::mat4 T8 = glm::translate(I,glm::vec3(-15.7,1.9,0.15));
    drawObjectTex(cylinder,texMetal,P,V,M*T8*R90z*S6);

}
void drawRetrovisor(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    drawPaloRetrovisor(P,V,M);
    drawEspejoRetrovisor(P,V,M);
}
void drawPaloRetrovisor(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(0.2, 1, 0.2));
    glm::mat4 T = glm::translate(I, glm::vec3(1, 2.0 ,0.5));
    glm::mat4 R = glm::rotate(I, glm::radians(-30.0f), glm::vec3(0, 0, 1));
    drawObjectTex(cylinder, texMetal, P, V, M*T*R*S);
}
void drawEspejoRetrovisor(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(1, 0.7, 0.2));
    glm::mat4 T = glm::translate(I, glm::vec3(1.9, 3.5 ,0));
    glm::mat4 R = glm::rotate(I, glm::radians(+50.0f), glm::vec3(0, 1, 0));
    drawObjectTex(cube,texMetalNegro, P, V, M*T*R*S);
}
void drawTuboEscape(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I,glm::vec3(0.2,5.5,0.2));
    glm::mat4 R = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,0,1));
    glm::mat4 T = glm::translate(I,glm::vec3(-14.7,1.3,1.5));
    drawObjectTex(torus,texMetal,P,V,M*T*R*S);

    glm::mat4 T2 = glm::translate(I,glm::vec3(-14.7,1.3,2));
    drawObjectTex(torus,texMetal,P,V,M*T2*R*S);

    glm::mat4 SC = glm::scale(I,glm::vec3(0.2,0.5,0.2));
    glm::mat4 RC = glm::rotate(I,glm::radians(115.0f),glm::vec3(0,0,1));
    glm::mat4 TC = glm::translate(I,glm::vec3(-13,1.5,1.5));
    drawObjectTex(cylinder,texMetal,P,V,M*TC*RC*SC);

    glm::mat4 TC2 = glm::translate(I,glm::vec3(-13,1.5,2));
    drawObjectTex(cylinder,texMetal,P,V,M*TC2*RC*SC);
}
void drawMaletero(glm::mat4 P,glm::mat4 V,glm::mat4 M){

    //MALETERO
    glm::mat4 R_MALETERO = glm::rotate(I, glm::radians(ROT_MALETERO), glm::vec3(0, 0, 1));


    //MALETERO (Para mover - glm::mat4 Rx = glm::rotate(I,glm::radians(-20.0f),glm::vec3(0,0,1));)
    glm::mat4 Sx = glm::scale(I,glm::vec3(0.15,0.3,3.1));
    glm::mat4 R20z = glm::rotate(I,glm::radians(-20.0f),glm::vec3(0,0,1));
    glm::mat4 Tx = glm::translate(I,glm::vec3(-15.4,2.8,0.1));
    drawObjectTex(cube,texRuby,P,V,M*Tx*R20z*Sx);

    glm::mat4 Sx2 = glm::scale(I,glm::vec3(1.2,0.05,3.2));
    glm::mat4 Rx = glm::rotate(I,glm::radians(5.0f),glm::vec3(0,0,1));
    glm::mat4 Tx2 = glm::translate(I,glm::vec3(-14.2,alturaMaletero,0.1));
    drawObjectTex(cube,texRuby,P,V,M*Tx2*Rx*R_MALETERO*Sx2);

    glm::mat4 S6 = glm::scale(I,glm::vec3(0.03,3.1,0.03));
    glm::mat4 R90z = glm::rotate(I,glm::radians(90.0f),glm::vec3(1,0,0));
    glm::mat4 T8 = glm::translate(I,glm::vec3(-15.4,3.2,0.15));
    drawObjectTex(cylinder,texMetal,P,V,M*T8*R90z*S6);
}
void drawAsientoDelantero(glm::mat4 P, glm::mat4 V, glm::mat4 M){

    glm::mat4 S2 = glm::scale(I, glm::vec3(3.4, 0.2, 1.55));
    glm::mat4 R2 = glm::rotate(I, glm::radians(+90.0f), glm::vec3(1, 0, 0));
    glm::mat4 T2 = glm::translate(I, glm::vec3(0, 1.55, 1.5));
    drawObjectTex(cube,texTigre, P, V, M*T2*R2*S2);

    //ASIENTO DERECHO
    AsientoIzquierdo(P,V,M);
    //ASIENTO IZQUIERDO
    AsientoDerecho(P,V,M);

    //PARTE DE EN MEDIO
    // Respaldo
    glm::mat4 Sa = glm::scale(I, glm::vec3(0.65, 1.6, 0.30));
    glm::mat4 Ta = glm::translate(I, glm::vec3(0, 1.6, 1.3));
    drawObjectTex(cylinder, texCueroNegro, P, V, M*Ta*Sa);

    glm::mat4 Sb = glm::scale(I, glm::vec3(0.4, 0.8, 1.2));
    glm::mat4 Rb = glm::rotate(I, glm::radians(+90.0f), glm::vec3(1, 0, 0));
    glm::mat4 Rb1 = glm::rotate(I, glm::radians(+90.0f), glm::vec3(0, 1, 0));
    glm::mat4 Tb = glm::translate(I, glm::vec3(0.0, 2.8, 1.5));
    drawObjectTex(torus, texCueroNegro, P, V, M*Tb*Rb*Rb1*Sb);

    // Base Palanca de cambios
    glm::mat4 Sc = glm::scale(I, glm::vec3(0.6, 0.33, 1.3));
    glm::mat4 Tc = glm::translate(I, glm::vec3(0, 0.4, 0));
    drawObjectTex(cube,texMetal, P, V, M*Tc*Sc);

    glm::mat4 Sd = glm::scale(I, glm::vec3(0.35, 0.60, 0.5));
    glm::mat4 Rd = glm::rotate(I, glm::radians(+90.0f), glm::vec3(0, 0, 1));
    glm::mat4 Td = glm::translate(I, glm::vec3(0, 0.45, -1.0));
    drawObjectTex(cylinder, texCueroNegro, P, V, M*Td*Rd*Sd);

    glm::mat4 Se = glm::scale(I, glm::vec3(0.6, 1.0, 0.8));
    glm::mat4 Re = glm::rotate(I, glm::radians(+3.0f), glm::vec3(1, 0, 0));
    glm::mat4 Te = glm::translate(I, glm::vec3(0, 0.75, -0.2));
    drawObjectTex(plane, texCueroNegro, P, V, M*Re*Te*Se);

    glm::mat4 Sf = glm::scale(I, glm::vec3(0.05, 1.0, 0.6));
    glm::mat4 Rf = glm::rotate(I, glm::radians(+90.0f), glm::vec3(1, 0, 0));
    glm::mat4 Rf_1 = glm::rotate(I, glm::radians(+90.0f), glm::vec3(0, 0, 1));
    glm::mat4 Tf = glm::translate(I, glm::vec3(0.6, 0.73, 0.0));
    glm::mat4 Rf_2 = glm::rotate(I, glm::radians(+1.0f), glm::vec3(1, 0, 0));
    drawObjectTex(triangle, texRuby, P, V, M*Rf_2*Tf*Rf_1*Rf*Sf);

    glm::mat4 Tf_2 = glm::translate(I, glm::vec3(-0.6, 0.73, 0.0));
    drawObjectTex(triangle, texRejillaMetal, P, V, M*Rf_2*Tf_2*Rf_1*Rf*Sf);

    glm::mat4 Sg = glm::scale(I, glm::vec3(0.2, 0.05, 0.05));
    glm::mat4 Tg = glm::translate(I, glm::vec3(0, 0.8, 0));
    drawObjectTex(cube,texMetal, P, V, M*Tg*Sg);

    glm::mat4 Tg_2 = glm::translate(I, glm::vec3(0, 0.8, -0.5));
    drawObjectTex(cube,texMetal, P, V, M*Tg_2*Sg);

    glm::mat4 Sg_2 = glm::scale(I, glm::vec3(0.3, 0.05, 0.05));
    glm::mat4 Rg = glm::rotate(I, glm::radians(+90.0f), glm::vec3(0, 1, 0));
    glm::mat4 Tg_3 = glm::translate(I, glm::vec3(0.15, 0.8, -0.25));
    drawObjectTex(cube,texMetal, P, V, M*Tg_3*Rg*Sg_2);

    glm::mat4 Tg_4 = glm::translate(I, glm::vec3(-0.15, 0.8, -0.25));
    drawObjectTex(cube,texMetal, P, V, M*Tg_4*Rg*Sg_2);

    //Palanca de cambios
    glm::mat4 Sh = glm::scale(I, glm::vec3(0.04, 0.6, 0.04));
    glm::mat4 Th = glm::translate(I, glm::vec3(0, 0.7, -0.3));
    drawObjectTex(cylinder, texMetalNegro, P, V, M*Th*Sh);

    glm::mat4 Si = glm::scale(I, glm::vec3(0.2, 0.2, 0.2));
    glm::mat4 Ti = glm::translate(I, glm::vec3(0.0, 1.5, -0.3));
    drawObjectTex(sphere, texMetal, P, V, M*Ti*Si);

}
void drawAsientoTrasero(glm::mat4 P, glm::mat4 V, glm::mat4 M){

    glm::mat4 S2 = glm::scale(I, glm::vec3(3.8, 0.2, 0.8));
    glm::mat4 R2 = glm::rotate(I, glm::radians(+90.0f), glm::vec3(1, 0, 0));
    glm::mat4 T2 = glm::translate(I, glm::vec3(0, 1.55, 1.5));
    drawObjectTex(cube,texCueroNegro, P, V, M*T2*R2*S2);

    glm::mat4 Sc = glm::scale(I,glm::vec3(0.3,1.6,0.7));
    glm::mat4 Rx = glm::rotate(I,glm::radians(90.0f),glm::vec3(1,0,0));
    glm::mat4 Tc = glm::translate(I,glm::vec3(-3.5,1.5,0));
    drawObjectTex(cylinder,texCueroNegro,P,V,M*Tc*Rx*Sc);

    glm::mat4 Tc2 = glm::translate(I,glm::vec3(3.5,1.5,0));
    drawObjectTex(cylinder,texCueroNegro,P,V,M*Tc2*Rx*Sc);

    //ASIENTO DERECHO
    glm::mat4 Ti = glm::translate(I, glm::vec3(0.3, 0, 0));
    AsientoIzquierdo(P,V,M*Ti);
    //ASIENTO IZQUIERDO
    glm::mat4 Td = glm::translate(I, glm::vec3(-0.3, 0, 0));
    AsientoDerecho(P,V,M*Td);
}
void AsientoIzquierdo(glm::mat4 P, glm::mat4 V, glm::mat4 M){

    glm::mat4 S1 = glm::scale(I, glm::vec3(1.4, 0.05, 1.5));
    glm::mat4 S3 = glm::scale(I, glm::vec3(0.4, 1.4, 0.2));
    glm::mat4 S3_2 = glm::scale(I, glm::vec3(0.7, 1.4, 0.2));
    glm::mat4 S3_3 = glm::scale(I, glm::vec3(0.5, 1.4, 0.3));
    glm::mat4 S4 = glm::scale(I, glm::vec3(0.05, 0.3, 0.05));
    glm::mat4 S5 = glm::scale(I, glm::vec3(0.4, 0.8, 0.3));
    glm::mat4 S = glm::scale(I, glm::vec3(1.4, 1.4, 0.15));
    glm::mat4 R3 = glm::rotate(I, glm::radians(+90.0f), glm::vec3(0, 0, 1));
    glm::mat4 R5 = glm::rotate(I, glm::radians(+90.0f), glm::vec3(0, 0, 1));
    glm::mat4 R = glm::rotate(I, glm::radians(+90.0f), glm::vec3(1, 0, 0));

    glm::mat4 T1_2 = glm::translate(I, glm::vec3(2, 0.1, 0));
    drawObjectTex(cube,texTigre, P, V, M*T1_2*S1);

    glm::mat4 T6 = glm::translate(I, glm::vec3(-2, 0.5, 1.3));
    drawObjectTex(cylinder, texTigre, P, V, M*T6*R3*S3);

    glm::mat4 T6_2 = glm::translate(I, glm::vec3(-2, 1.6, 1.3));
    drawObjectTex(cylinder, texTigre, P, V, M*T6_2*R3*S3_2);

    glm::mat4 T6_3 = glm::translate(I, glm::vec3(-2, 2.7, 1.45));
    drawObjectTex(cylinder, texTigre, P, V, M*T6_3*R3*S3_3);

    glm::mat4 T7 = glm::translate(I, glm::vec3(-2.35, 3.35, 1.45));
    drawObjectTex(cylinder, texMetalNegro, P, V, M*T7*S4);

    glm::mat4 T7_1 = glm::translate(I, glm::vec3(-1.65, 3.35, 1.45));
    drawObjectTex(cylinder, texMetalNegro, P, V, M*T7_1*S4);

    glm::mat4 T8 = glm::translate(I, glm::vec3(-2, 4, 1.45));
    drawObjectTex(cylinder, texTigre, P, V, M*T8*R5*S5);

    glm::mat4 T_1 = glm::translate(I, glm::vec3(-2, 0.2, 0));
    drawObjectTex(cylinder, texTigre, P, V, M*T_1*R*S);

}
void AsientoDerecho(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S1 = glm::scale(I, glm::vec3(1.4, 0.05, 1.5));
    glm::mat4 T1 = glm::translate(I, glm::vec3(-2, 0.1, 0));
    drawObjectTex(cube,texTigre, P, V, M*T1*S1);

    glm::mat4 S3 = glm::scale(I, glm::vec3(0.4, 1.4, 0.2));
    glm::mat4 R3 = glm::rotate(I, glm::radians(+90.0f), glm::vec3(0, 0, 1));
    glm::mat4 T3 = glm::translate(I, glm::vec3(2, 0.5, 1.3));
    drawObjectTex(cylinder, texTigre, P, V, M*T3*R3*S3);

    glm::mat4 S3_2 = glm::scale(I, glm::vec3(0.7, 1.4, 0.2));
    glm::mat4 T3_2 = glm::translate(I, glm::vec3(2, 1.6, 1.3));
    drawObjectTex(cylinder, texTigre, P, V, M*T3_2*R3*S3_2);

    glm::mat4 S3_3 = glm::scale(I, glm::vec3(0.5, 1.4, 0.3));
    glm::mat4 T3_3 = glm::translate(I, glm::vec3(2, 2.7, 1.45));
    drawObjectTex(cylinder, texTigre, P, V, M*T3_3*R3*S3_3);


    glm::mat4 S4 = glm::scale(I, glm::vec3(0.05, 0.3, 0.05));
    glm::mat4 T4 = glm::translate(I, glm::vec3(2.35, 3.35, 1.45));
    drawObjectTex(cylinder, texMetalNegro, P, V, M*T4*S4);

    glm::mat4 T4_1 = glm::translate(I, glm::vec3(1.65, 3.35, 1.45));
    drawObjectTex(cylinder, texMetalNegro, P, V, M*T4_1*S4);

    glm::mat4 S5 = glm::scale(I, glm::vec3(0.4, 0.8, 0.3));
    glm::mat4 R5 = glm::rotate(I, glm::radians(+90.0f), glm::vec3(0, 0, 1));
    glm::mat4 T5 = glm::translate(I, glm::vec3(2, 4, 1.45));
    drawObjectTex(cylinder, texTigre, P, V, M*T5*R5*S5);

    glm::mat4 S = glm::scale(I, glm::vec3(1.4, 1.4, 0.15));
    glm::mat4 T = glm::translate(I, glm::vec3(2, 0.2, 0));
    glm::mat4 R = glm::rotate(I, glm::radians(+90.0f), glm::vec3(1, 0, 0));
    drawObjectTex(cylinder, texTigre, P, V, M*T*R*S);

}
void drawRuedas(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    //NEUMATICO
    glm::mat4 S = glm::scale(I,glm::vec3(1,1.5,1));
    glm::mat4 R = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,0,1));
    drawObjectTex(torus,texNeumatico,P,V,M*R*S);

    //LLANTA
    Llanta(P,V,M);

}
void Llanta(glm::mat4 P, glm::mat4 V, glm::mat4 M){

    // TIEMPO PARA GIRAR
    //glm::mat4 Rt = glm::rotate(I, glm::radians(Rtiempo), glm::vec3(1, 0, 0));


    // Llanta externa
    glm::mat4 S1 = glm::scale(I,glm::vec3(0.85,0.25,0.85));
    glm::mat4 R1 = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,0,1));
    //glm::mat4 T1 = glm::translate(I,glm::vec3(0.30,2,0));
    drawObjectTex(torus,texMetal,P,V,M*R1*S1);

    glm::mat4 S1_2 = glm::scale(I,glm::vec3(0.90,0.25,0.90));
    //glm::mat4 T1_2 = glm::translate(I,glm::vec3(0.32,2,0));
    drawObjectTex(torus,texGold,P,V,M*R1*S1_2);

    // Cilindro y logo
    glm::mat4 S2 = glm::scale(I,glm::vec3(0.15,0.1,0.15));
    glm::mat4 R2 = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,0,1));
    //glm::mat4 T2 = glm::translate(I,glm::vec3(0,2,0));
    drawObjectTex(cylinder,texMetalNegro,P,V,M*R2*S2);

    glm::mat4 Sm = glm::scale(I,glm::vec3(0.1,0.1,0.1));
    glm::mat4 Rm = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,1,0));
    glm::mat4 Tm = glm::translate(I,glm::vec3(0.10,0,0));
    drawObjectTex(monkey,texGold,P,V,M*Tm*Rm*Sm);

    // Rayos
    glm::mat4 S_aspa = glm::scale(I, glm::vec3(0.02, 0.7, 1));
    float grados=0;
    for(int i=0; i<20; i++){
        grados += 18.0f;
        glm::mat4 R = glm::rotate(I, glm::radians(grados), glm::vec3(1, 0, 0));
        drawObjectTex(triangle, texMetal, P, V, M*R*S_aspa);
    }

}
void drawCristales(glm::mat4 P,glm::mat4 V,glm::mat4 M){
    Ventanas(P,V,M);
}
void Ventanas(glm::mat4 P,glm::mat4 V,glm::mat4 M){

    float trasVentana=trasPuertax;
    if(rotPuerta>10)
        trasVentana=trasPuertax+0.4;

    //Apertura de la ventana derecha(junto a la puerta)
    glm::mat4 RotacionDer = glm::rotate(I,glm::radians(-rotPuerta),glm::vec3(0,1,0));
    glm::mat4 T_der = glm::translate(I,glm::vec3(trasVentana,0,-trasPuertaz));

    //Apertura de la ventana izquierda(junto a la puerta)
    glm::mat4 RotacionIzq = glm::rotate(I,glm::radians(rotPuerta),glm::vec3(0,1,0));
    glm::mat4 T_izq = glm::translate(I,glm::vec3(trasVentana,0,trasPuertaz));

    // Ventana delantera derecha
    glm::mat4 S = glm::scale(I,glm::vec3(1,0,0.8));
    glm::mat4 R = glm::rotate(I,glm::radians(90.0f),glm::vec3(1,0,0));
    glm::mat4 T = glm::translate(I,glm::vec3(-7.9,alturaVentana,3.2));
    glDepthMask(GL_FALSE); //Para la profundidad
    drawObjectMat(plane,cyan,P,V,M*T_izq*T*RotacionIzq*R*S);
    glDepthMask(GL_TRUE);

    glm::mat4 St = glm::scale(I, glm::vec3(1, 0.8, 0));
    glm::mat4 Tt = glm::translate(I, glm::vec3(-6.9, alturaVentana, 3.2));
    if(rotPuerta<10) {
        glDepthMask(GL_FALSE);//Para la profundidad
        drawObjectMat(triangle, cyan, P, V, M * Tt * St);
        glDepthMask(GL_TRUE);
    }

    // Ventana delantera izquierda
    glm::mat4 T_1 = glm::translate(I,glm::vec3(-7.9,alturaVentana,-3));
    glDepthMask(GL_FALSE);//Para la profundidad
    drawObjectMat(plane,cyan,P,V,M*T_der*T_1*RotacionDer*R*S);
    glDepthMask(GL_TRUE);

    if(rotPuerta<10) {
        glm::mat4 Tt2 = glm::translate(I, glm::vec3(-6.9, alturaVentana, -3));
        glDepthMask(GL_FALSE);//Para la profundidad
        drawObjectMat(triangle, cyan, P, V, M * Tt2 * St);
        glDepthMask(GL_TRUE);
    }

    // Ventana trasera izquierda
    glm::mat4 S1 = glm::scale(I,glm::vec3(1.3,0,0.8));
    glm::mat4 T1 = glm::translate(I,glm::vec3(-10.5,alturaVentana,3.2));
    glDepthMask(GL_FALSE);//Para la profundidad
    drawObjectMat(plane,cyan,P,V,M*T1*R*S1);
    glDepthMask(GL_TRUE);

    glm::mat4 T1_1 = glm::translate(I,glm::vec3(-10.5,alturaVentana,-3));
    glDepthMask(GL_FALSE);//Para la profundidad
    drawObjectMat(plane,cyan,P,V,M*T1_1*R*S1);
    glDepthMask(GL_TRUE);

    // Ventana trasera derecha
    glm::mat4 Tt3 = glm::translate(I,glm::vec3(-11.8,alturaVentana,3.2));
    glDepthMask(GL_FALSE);//Para la profundidad
    drawObjectMat(triangle,cyan,P,V,M*Tt3*St);
    glDepthMask(GL_TRUE);

    glm::mat4 Tt4 = glm::translate(I,glm::vec3(-11.8,alturaVentana,-3));
    glDepthMask(GL_FALSE);//Para la profundidad
    drawObjectMat(triangle,cyan,P,V,M*Tt4*St);
    glDepthMask(GL_TRUE);

    //Barrotes entre ventana
    glm::mat4 Sb = glm::scale(I,glm::vec3(0.2,0.9,0.1));
    glm::mat4 Tb = glm::translate(I,glm::vec3(-9,4.1,-3));
    drawObjectTex(cube,texRuby,P,V,M*Tb*Sb);

    glm::mat4 Tb2 = glm::translate(I,glm::vec3(-9,4.1,3.2));
    drawObjectTex(cube,texRuby,P,V,M*Tb2*Sb);

}
void drawParabrisas(glm::mat4 P,glm::mat4 V,glm::mat4 M){
    // Parabrisas
    glm::mat4 Sc = glm::scale(I,glm::vec3(1.5,0,1.4));
    glm::mat4 R1c = glm::rotate(I,glm::radians(-10.0f),glm::vec3(0,1,0));
    glm::mat4 R2c = glm::rotate(I,glm::radians(120.0f),glm::vec3(0,0,1));
    glm::mat4 R3c = glm::rotate(I,glm::radians(-8.0f),glm::vec3(0,1,0));
    glm::mat4 Tc = glm::translate(I,glm::vec3(-6,4,1.6));
    glDepthMask(GL_FALSE);//Para la profundidad
    drawObjectMat(plane,cyan,P,V,M*Tc*R3c*R2c*R1c*Sc);
    glDepthMask(GL_TRUE);
    glm::mat4 R1c1 = glm::rotate(I,glm::radians(10.0f),glm::vec3(0,1,0));
    glm::mat4 R2c1 = glm::rotate(I,glm::radians(120.0f),glm::vec3(0,0,1));
    glm::mat4 R3c1 = glm::rotate(I,glm::radians(8.0f),glm::vec3(0,1,0));
    glm::mat4 Tc1 = glm::translate(I,glm::vec3(-6,4,-1.35));
    glDepthMask(GL_FALSE);//Para la profundidad
    drawObjectMat(plane,cyan,P,V,M*Tc1*R3c1*R2c1*R1c1*Sc);
    glDepthMask(GL_TRUE);

    glm::mat4 S1c = glm::scale(I,glm::vec3(0.1,1,0));
    glm::mat4 R4c = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,1,0));
    glm::mat4 R5c = glm::rotate(I,glm::radians(5.0f),glm::vec3(1,0,0));
    glm::mat4 R6c = glm::rotate(I,glm::radians(25.0f),glm::vec3(0,0,1));
    glm::mat4 T1c = glm::translate(I,glm::vec3(-6.2,4.2,3));

    glDepthMask(GL_FALSE);//Para la profundidad
    drawObjectMat(triangle,cyan,P,V,M*T1c*R6c*R5c*R4c*S1c);
    glDepthMask(GL_TRUE);

    glm::mat4 S1c1 = glm::scale(I,glm::vec3(0.1,1,0));
    glm::mat4 R4c1 = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,1,0));
    glm::mat4 R5c1 = glm::rotate(I,glm::radians(-5.0f),glm::vec3(1,0,0));
    glm::mat4 R6c1 = glm::rotate(I,glm::radians(25.0f),glm::vec3(0,0,1));
    glm::mat4 T1c1 = glm::translate(I,glm::vec3(-6.2,4.2,-2.8));

    glDepthMask(GL_FALSE);//Para la profundidad
    drawObjectMat(triangle,cyan,P,V,M*T1c1*R6c1*R5c1*R4c1*S1c1);
    glDepthMask(GL_TRUE);

    glm::mat4 SM = glm::scale(I,glm::vec3(0.3,1.1,0));
    glm::mat4 RM = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,1,0));
    glm::mat4 RM2 = glm::rotate(I,glm::radians(180.0f),glm::vec3(1,0,0));
    glm::mat4 RM3 = glm::rotate(I,glm::radians(31.0f),glm::vec3(0,0,1));
    glm::mat4 TM = glm::translate(I,glm::vec3(-6.1,4.5,0.1));
    glDepthMask(GL_FALSE);//Para la profundidad
    drawObjectMat(triangle,cyan,P,V,M*TM*RM3*RM2*RM*SM);
    glDepthMask(GL_TRUE);

}
void drawTecho(glm::mat4 P,glm::mat4 V,glm::mat4 M){

    glm::mat4 S = glm::scale(I,glm::vec3(0.1,1.1,3.1));
    glm::mat4 R = glm::rotate(I,glm::radians(-32.0f),glm::vec3(0,0,1));
    glm::mat4 T = glm::translate(I,glm::vec3(-12.5,4.1,0.1));
    drawObjectTex(cube,texMetal,P,V,M*T*R*S);

    glm::mat4 S1 = glm::scale(I,glm::vec3(3.1,0.35,3));
    glm::mat4 R1 = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,1,0));
    glm::mat4 R2 = glm::rotate(I,glm::radians(-20.0f),glm::vec3(0,0,1));
    glm::mat4 T1 = glm::translate(I,glm::vec3(-11.9,5.4,0.1));
    drawObjectTex(triangle,texMetal,P,V,M*T1*R2*R1*S1);

    glm::mat4 St = glm::scale(I,glm::vec3(2.6,0.1,1.7));
    glm::mat4 Rt = glm::rotate(I,glm::radians(-9.0f),glm::vec3(1,0,0));
    glm::mat4 Tt = glm::translate(I,glm::vec3(-9.2,5.3,-1.35));
    drawObjectTex(cube,texMetal,P,V,M*Tt*Rt*St);

    glm::mat4 St1 = glm::scale(I,glm::vec3(2.6,0.1,1.7));
    glm::mat4 Rt1 = glm::rotate(I,glm::radians(9.0f),glm::vec3(1,0,0));
    glm::mat4 Tt1 = glm::translate(I,glm::vec3(-9.2,5.3,1.5));
    drawObjectTex(cube,texMetal,P,V,M*Tt1*Rt1*St1);

    glm::mat4 Rl = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,0,1));
    glm::mat4 Tl  = glm::translate(I,glm::vec3(-9.2,5.6,0.1));
    glm::mat4 Sl = glm::scale(I,glm::vec3(0.05,2.6,0.05));
    drawObjectTex(cylinder,texRuby,P,V,M*Tl*Rl*Sl);

}


void drawEscena(glm::mat4 P, glm::mat4 V, glm::mat4 M){

    drawCarretera(P,V,M);

    if(numeroEscena%2==0){
        glm::mat4 Tbanco1 = glm::translate(I,glm::vec3(-6,0.8,-17.5));
        drawBank(P,V,M*Tbanco1);

        glm::mat4 Rbanco = glm::rotate(I,glm::radians(180.0f),glm::vec3(0,1,0));
        glm::mat4 Tbanco2 = glm::translate(I,glm::vec3(-6,0.8,27.5));
        drawBank(P,V,M*Tbanco2*Rbanco);
    }

    int x = 32;
    int y = 0;
    for(int i=0; i<13; i++){
        glm::mat4 TX = glm::translate(I, glm::vec3(x,2.5,19));
        drawValla(P,V,M*TX);
        x -=6;
        y+=0.05;
    }

    x = 32;
    y = 0;
    for(int i=0; i<13; i++){
        glm::mat4 TX = glm::translate(I, glm::vec3(x,2.5,-7));
        drawValla(P,V,M*TX);
        x -=6;
    }

    if(numeroEscena%3==0) {
        drawStop(P, V, M);
        drawArboles(P, V, M);
        drawArdillas(P,V,M);
    }

    drawTronco(P,V,M);

    glm::mat4 T_aleat1 = glm::translate(I,glm::vec3(0,0,0));
    glm::mat4 T_aleat2 = glm::translate(I,glm::vec3(0,0,0));
    if(numeroEscena%2==0) {
        glm::mat4 T_aleat1 =glm::translate(I,glm::vec3(5,0,0));
        glm::mat4 T_aleat2 =glm::translate(I,glm::vec3(-5,0,0));
    }
    glm::mat4 T_Casa = glm::translate(I,glm::vec3(-7,10,13));
    glm::mat4 R_casaY = glm::rotate(I,glm::radians(-90.0f),glm::vec3(0,1,0));
    glm::mat4 R_casaX = glm::rotate(I,glm::radians(90.0f),glm::vec3(1,0,0));
    glm::mat4 S_casa = glm::scale(I,glm::vec3(10,10,42 ));
    drawCasa(P,V,M*T_Casa*R_casaX*R_casaY*S_casa);

    glm::mat4 T_Casa2 = glm::translate(I,glm::vec3(-7,10,-80));
    drawPaisaje(P,V,M*T_Casa2*R_casaX*R_casaY*S_casa);

    glm::mat4 S = glm::scale(I,glm::vec3(2,2,2));
    glm::mat4 T = glm::translate(I,glm::vec3(-27,0.5,-19));
    drawFarola(P,V,M*T_aleat1*T*S);

    glm::mat4 T2 = glm::translate(I,glm::vec3(14,0.5,-19));
    drawFarola(P,V,M*T_aleat2*T2*S);

    glm::mat4 T3 = glm::translate(I,glm::vec3(-27,0.5,30));
    drawFarola(P,V,M*T_aleat1*T3*S);

    glm::mat4 T4 = glm::translate(I,glm::vec3(14,0.5,30));
    drawFarola(P,V,M*T_aleat2*T4*S);

}
void drawFarola(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(0.25, 0.5, 0.25));
    glm::mat4 S2 = glm::scale(I, glm::vec3(0.8, 0.6, 0.8));
    glm::mat4 S3 = glm::scale(I, glm::vec3(0.25, 0.25, 0.25));
    glm::mat4 T = glm::translate(I, glm::vec3(0, 0 ,0.25));
    glm::mat4 T1 = glm::translate(I, glm::vec3(0, 0 ,-0.3));
    glm::mat4 T2 = glm::translate(I, glm::vec3(0, 3.5 ,0.5));

    drawBaseFarola(P,V,M*T*S);
    drawPaloFarola(P,V,M*T1*S2);
    drawCabezaFarola(P,V,M*T2*S3);
}
void drawBaseFarola(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 T = glm::translate(I, glm::vec3(0, 0.8 ,0));

    glm::mat4 Juntar1 = glm::translate(I, glm::vec3(0, 0.0 ,0.5));
    glm::mat4 R = glm::rotate(I, glm::radians(30.0f), glm::vec3(1, 0, 0));
    glm::mat4 R90y = glm::rotate(I, glm::radians(90.0f), glm::vec3(0, 1, 0));
    drawObjectTex(triangle,texMetalNegro, P, V, M*T*Juntar1*R);

    glm::mat4 Juntar2 = glm::translate(I, glm::vec3(-0.5, 0.0 ,0));
    glm::mat4 Tm = glm::translate(I, glm::vec3(1, 0 ,1));
    glm::mat4 R1 = glm::rotate(I, glm::radians(-30.0f), glm::vec3(1, 0, 0));
    drawObjectTex(triangle,texMetalNegro, P, V, M*T*Juntar2*Tm*R90y*R1);

    glm::mat4 Juntar3 = glm::translate(I, glm::vec3(0.5, 0.0 ,0));
    glm::mat4 mTm = glm::translate(I, glm::vec3(-1, 0 ,1));
    drawObjectTex(triangle,texMetalNegro, P, V, M*T*Juntar3*mTm*R90y*R);

    glm::mat4 T4 = glm::translate(I, glm::vec3(0, 0.0 ,2));
    glm::mat4 Juntar4 = glm::translate(I, glm::vec3(0, 0.0 ,-0.5));
    drawObjectTex(triangle,texMetalNegro, P, V, M*T*Juntar4*T4*R1);

}
void drawPaloFarola(glm::mat4 P, glm::mat4 V, glm::mat4 M){
    glm::mat4 S = glm::scale(I, glm::vec3(0.1, 3, 0.1));
    glm::mat4 R = glm::rotate(I, glm::radians(-30.0f), glm::vec3(1, 0, 0));
    glm::mat4 T = glm::translate(I, glm::vec3(0, 3.0 ,1));
    drawObjectTex(cylinder,texMetalNegro, P, V, M*T*S);

    glm::mat4 S1 = glm::scale(I,glm::vec3(0.1,0.1,0.1));
    drawObjectTex(torus,texMetalNegro,P,V,M*T*S1);

    glm::mat4 S2 = glm::scale(I,glm::vec3(0.15,0.15,0.15));
    glm::mat4 T1 = glm::translate(I, glm::vec3(0, 3.05 ,1));
    drawObjectTex(torus,texMetalNegro,P,V,M*T1*S2);

    glm::mat4 T2 = glm::translate(I, glm::vec3(0, 3.1 ,1));
    drawObjectTex(torus,texMetalNegro,P,V,M*T2*S1);


    glm::mat4 T3 = glm::translate(I, glm::vec3(0, 5.0 ,1));
    drawObjectTex(torus,texMetalNegro,P,V,M*T3*S1);

    glm::mat4 T4 = glm::translate(I, glm::vec3(0, 5.05 ,1));
    drawObjectTex(torus,texMetalNegro,P,V,M*T4*S2);

    glm::mat4 T5 = glm::translate(I, glm::vec3(0, 5.1 ,1));
    drawObjectTex(torus,texMetalNegro,P,V,M*T5*S1);
}
void drawCabezaFarola(glm::mat4 P, glm::mat4 V, glm::mat4 M){

    glm::mat4 Si = glm::scale(I, glm::vec3(0.9, 0.05, 0.9));
    glm::mat4 Ti = glm::translate(I, glm::vec3(0, -0.05, 0));
    drawObjectTex(cylinder,texMetalNegro,P,V,M*Ti*Si);

    float a=0.9;
    float b=-0.05;
    for(int i=0; i<10; i++){
        a -=0.1;
        b-=0.05;
        glm::mat4 SX = glm::scale(I, glm::vec3(a, 0.05, a));
        glm::mat4 TX = glm::translate(I, glm::vec3(0,b, 0));
        drawObjectTex(cylinder,texMetalNegro, P, V, M*TX*SX);
    }

    glm::mat4 S = glm::scale(I, glm::vec3(0.9, 0.05, 0.9));
    drawObjectTex(cube,texMetalNegro, P, V, M*S);

    glm::mat4 S2 = glm::scale(I, glm::vec3(0.15, 1.3, 0.15));
    glm::mat4 T = glm::translate(I, glm::vec3(0.80, 1.3, 0.80));
    drawObjectTex(cube,texMetalNegro, P, V, M*T*S2);

    glm::mat4 T2 = glm::translate(I, glm::vec3(-0.80, 1.3, 0.80));
    drawObjectTex(cube,texMetalNegro, P, V, M*T2*S2);

    glm::mat4 T3 = glm::translate(I, glm::vec3(-0.80, 1.3, -0.80));
    drawObjectTex(cube,texMetalNegro, P, V, M*T3*S2);

    glm::mat4 T4 = glm::translate(I, glm::vec3(0.80, 1.3, -0.80));
    drawObjectTex(cube,texMetalNegro, P, V, M*T4*S2);

    glm::mat4 S3 = glm::scale(I, glm::vec3(0.95, 0.05, 0.95));
    glm::mat4 T5 = glm::translate(I, glm::vec3(0, 2.6, 0));
    drawObjectTex(cube,texMetalNegro, P, V, M*T5*S3);

    glm::mat4 S4 = glm::scale(I, glm::vec3(1, 0.05, 1));
    glm::mat4 T6 = glm::translate(I, glm::vec3(0, 2.7, 0));
    drawObjectTex(cube,texMetalNegro, P, V, M*T6*S4);

    float x=1;
    float y=2.7;
    for(int i=0; i<10; i++){
        x -=0.1;
        y+=0.05;
        glm::mat4 SX = glm::scale(I, glm::vec3(x, 0.05, x));
        glm::mat4 TX = glm::translate(I, glm::vec3(0,y, 0));
        drawObjectTex(cube,texMetalNegro, P, V, M*TX*SX);
    }

    glm::mat4 R = glm::rotate(I, glm::radians(90.0f), glm::vec3(1, 0, 0));
    glm::mat4 SC = glm::scale(I, glm::vec3(0.8, 0.8, 1.3));
    glm::mat4 TC = glm::translate(I, glm::vec3(0, 1.3, -0.8));
    glDepthMask(GL_FALSE);
    drawObjectMat(plane,cyan, P, V, M*TC*R*SC);
    glDepthMask(GL_TRUE);

    glm::mat4 TC2 = glm::translate(I, glm::vec3(0, 1.3, 0.8));
    glDepthMask(GL_FALSE);
    drawObjectMat(plane,cyan, P, V, M*TC2*R*SC);
    glDepthMask(GL_TRUE);

    glm::mat4 R2 = glm::rotate(I, glm::radians(90.0f), glm::vec3(0, 0, 1));
    glm::mat4 SC2 = glm::scale(I, glm::vec3(1.3, 0.8, 0.8));
    glm::mat4 TC3 = glm::translate(I, glm::vec3(0.8, 1.3, 0));
    glDepthMask(GL_FALSE);
    drawObjectMat(plane,cyan, P, V, M*TC3*R2*SC2);
    glDepthMask(GL_TRUE);

    glm::mat4 TC4 = glm::translate(I, glm::vec3(-0.8, 1.3, 0));
    glDepthMask(GL_FALSE);
    drawObjectMat(plane,cyan, P, V, M*TC4*R2*SC2);
    glDepthMask(GL_TRUE);
}

void drawCarretera(glm::mat4 P,glm::mat4 V,glm::mat4 M){

    //caretera del medio
    glm::mat4 S = glm::scale(I,glm::vec3(42,0.1,12));
    glm::mat4 T = glm::translate(I,glm::vec3(-7,0,6));
    drawObjectTex(cube,texRoad,P,V,M*T*S);

    //acera izquierda
    glm::mat4 S3 = glm::scale(I,glm::vec3(42,0.5,7));
    glm::mat4 T4 = glm::translate(I,glm::vec3(-7,0.3,25));
    drawObjectTex(cube,texAcera,P,V,M*T4*S3);

    //acera derecha
    glm::mat4 T5 = glm::translate(I,glm::vec3(-7,0.3,-13));
    drawObjectTex(cube,texAcera,P,V,M*T5*S3);

    //cesped derecha
    glm::mat4 S4 = glm::scale(I,glm::vec3(42,0.5,15));
    glm::mat4 T6 = glm::translate(I,glm::vec3(-7,-0.2,-27));
    drawObjectTex(cube,texCesped,P,V,M*T6*S4);

    //cesped izquierda
    glm::mat4 T7 = glm::translate(I,glm::vec3(-7,-0.2,38));
    drawObjectTex(cube,texCesped,P,V,M*T7*S4);
}
void drawValla(glm::mat4 P,glm::mat4 V,glm::mat4 M){

    //Palo vertical
    glm::mat4 S = glm::scale(I,glm::vec3(0.2,2,0.2));
    glm::mat4 T = glm::translate(I,glm::vec3(0,0,0));
    drawObjectTex(cylinder,texWood,P,V,M*T*S);

    //Palo vertical 2
    glm::mat4 T2 = glm::translate(I,glm::vec3(-6,0,0));
    drawObjectTex(cylinder,texWood,P,V,M*T2*S);

    //Palo Horizontal
    glm::mat4 S2 = glm::scale(I,glm::vec3(0.2,3.5,0.2));
    glm::mat4 T3 = glm::translate(I,glm::vec3(-3,1,0));
    glm::mat4 R = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,0,1));
    drawObjectTex(cylinder,texWood,P,V,M*T3*R*S2);

    //Palo Horizontal2
    glm::mat4 T4 = glm::translate(I,glm::vec3(-3,-0.5,0));
    drawObjectTex(cylinder,texWood,P,V,M*T4*R*S2);

    glm::mat4 S_sphere = glm::scale(I,glm::vec3(0.2,0.2,0.2));
    glm::mat4 T_sphere = glm::translate(I,glm::vec3(0,2.2,0));
    drawObjectTex(sphere,texWood,P,V,M*T_sphere*S_sphere);

    glm::mat4 T_sphere2 = glm::translate(I,glm::vec3(-6,2.2,0));
    drawObjectTex(sphere,texWood,P,V,M*T_sphere2*S_sphere);
}
void drawBank(glm::mat4 P,glm::mat4 V,glm::mat4 M){
    glm::mat4 T = glm::translate(I,glm::vec3(0,0,0));

    glm::mat4 S = glm::scale(I,glm::vec3(0.05,0.05,0.05));
    drawObjectTex(bank,texBench,P,V,M*T*S);
}
void drawStop(glm::mat4 P,glm::mat4 V,glm::mat4 M){
    glm::mat4 T = glm::translate(I,glm::vec3(35,0,-5));

    glm::mat4 R = glm::rotate(I,glm::radians(30.0f),glm::vec3(0,1,0));
    drawObjectTex(stop,texStop,P,V,M*T*R);
}
void drawTronco(glm::mat4 P,glm::mat4 V,glm::mat4 M){

    glm::mat4 S = glm::scale(I,glm::vec3(5,3,2));
    glm::mat4 R = glm::rotate(I,glm::radians(45.0f),glm::vec3(0,1,0));
    glm::mat4 T = glm::translate(M,glm::vec3(-15,0.5,38));
    drawObjectTex(tronco, texTronco, P, V, T*R*S);

    glm::mat4 T2 = glm::translate(M,glm::vec3(-19,0.5,-30));
    drawObjectTex(tronco, texTronco, P, V, T2*R*S);

    glm::mat4 T3 = glm::translate(M,glm::vec3(6,0.5,38));
    drawObjectTex(tronco, texTronco, P, V, T3*R*S);

    glm::mat4 T4 = glm::translate(M,glm::vec3(9,0.5,-30));
    drawObjectTex(tronco, texTronco, P, V, T4*R*S);

}
void drawArboles(glm::mat4 P,glm::mat4 V,glm::mat4 M){

    glm::mat4 S = glm::scale(I,glm::vec3(0.05,0.05,0.05));
    glm::mat4 R = glm::rotate(I,glm::radians(-90.0f),glm::vec3(1,0,0));
    glm::mat4 T = glm::translate(I,glm::vec3(-6,0.5,38));
    drawObjectTex(arbol, texArbol, P, V, M*T*R*S);

    glm::mat4 T2 = glm::translate(I,glm::vec3(6,0.5,-30));
    drawObjectTex(arbol, texArbol, P, V, M*T2*R*S);

}
void drawArdillas(glm::mat4 P,glm::mat4 V,glm::mat4 M){

    glm::mat4 S = glm::scale(I,glm::vec3(0.05,0.05,0.05));
    glm::mat4 R = glm::rotate(I,glm::radians(-90.0f),glm::vec3(1,0,0));
    glm::mat4 R2 = glm::rotate(I,glm::radians(180.0f),glm::vec3(0,1,0));
    glm::mat4 T = glm::translate(I,glm::vec3(-6,9,32.7));
    //suba
    glm::mat4 mov = glm::rotate(I,glm::radians(asomar),glm::vec3(0,1,0));
    drawObjectTex(ardilla, texArdilla, P, V, M*T*mov*R2*R*S);

    //asoma
    glm::mat4 R3 = glm::rotate(I,glm::radians(90.0f),glm::vec3(0,1,0));
    glm::mat4 T2 = glm::translate(I,glm::vec3(5,asomar2,-30));
    drawObjectTex(ardilla, texArdilla, P, V, M*T2*R3*R*S);

}
void drawCasa(glm::mat4 P,glm::mat4 V,glm::mat4 M){
    glm::mat4 T = glm::translate(I,glm::vec3(0,4,0));
    if(noche){
        drawObjectTex(plane,texPaisajeModerno,P,V,M*T);
    }else{
        drawObjectTex(plane,texCasa,P,V,M*T);
    }
}
void drawPaisaje(glm::mat4 P,glm::mat4 V,glm::mat4 M){
    glm::mat4 T = glm::translate(I,glm::vec3(0,4,0));
    if(noche){
        drawObjectTex(plane,texPaisajeModerno,P,V,M*T);
    }else{
        drawObjectTex(plane,texCasa,P,V,M*T);
    }
}

void MovimientoArdillas(){
    // Movimiento ardillas
    if(asomar>60)
        asomar=-60.0;
    asomar+=3;

    if(asomar2>5)
        asomar2=0.0;
    asomar2+=0.2;
}
void ControlCoche(){
    if(wMov<-34) {
        wMov = 29.0;
        if(numeroEscena<=0)
            numeroEscena++;
        else
            numeroEscena--;
    }
    else if(wMov>31) {
        wMov = -30.0;
        numeroEscena++;
    }
    if(aMov>0) {
        aMov = 0.0;
        rotVolante=0.0;
    }
    else if(aMov<-12) {
        aMov = -12.0;
        rotVolante=120.0;
    }

}

//Tamaño de la pantalla
void funFramebufferSize(GLFWwindow* window, int width, int height) {

    // Configuracion del Viewport
    glViewport(0, 0, width, height);

    // Actualizacion de w y h
    w = width;
    h = height;

}

//Teclas
void funKey(GLFWwindow* window, int key  , int scancode, int action, int mods) {
    switch(key) {
        case GLFW_KEY_T:
            if(action==GLFW_PRESS)
                techo+=1;
            break;
        case GLFW_KEY_W:
            wMov -= 1;
            rotRuedas-=3;
            break;
        case GLFW_KEY_S:
            wMov += 1;
            rotRuedas+=3;
            break;
        case GLFW_KEY_A:
            aMov += 0.5;
            rotVolante -=5;
            break;
        case GLFW_KEY_D:
            aMov -= 0.5;
            rotVolante +=5;
            break;
        case GLFW_KEY_1:
            camaraCoche = true;
            xEye = -8.5;
            yEye = 4;
            zEye = -2;

            xCenter = 20;
            yCenter = 0;
            zCenter = 0;

            alphaX = 10;
            alphaY = 10;
            break;
        case GLFW_KEY_2:
            camaraCoche = true;
            xEye = -30;
            yEye = 15;
            zEye = 0;

            xCenter = 0;
            yCenter = 0;
            zCenter = 0;

            break;
        case GLFW_KEY_3:
           camaraCoche = false;
            xEye = 0;
            yEye = 0;
            zEye = 0;

            xCenter = -6;
            yCenter = 1;
            zCenter = 0;
            break;
        case GLFW_KEY_LEFT:
            if(rotPuerta>0 && aMov>-9) {
                rotPuerta -= 2;
                trasPuertax -=0.02;
                trasPuertaz -=0.05;
            }

            break;
        case GLFW_KEY_RIGHT:
            if(rotPuerta<50 && aMov>-2) {
                rotPuerta += 2;
                trasPuertax +=0.02;
                trasPuertaz +=0.05;
            }
            break;
        default:
            break;
    }
}

void character_callback(GLFWwindow* window, unsigned int codepoint){
    if(codepoint == 82 && alturaMaletero>3.3){// R
        ROT_MALETERO += 5.0;
        alturaMaletero-=0.1;
    }
    else if(codepoint == 114 && alturaMaletero<4){ // r
        ROT_MALETERO -= 5.0;
        alturaMaletero+=0.1;
    }
    else if(codepoint == 86 && alturaVentana<4.1){// V
        alturaVentana += 0.1;
    }
    else if(codepoint == 118 && alturaVentana>2.7){ // v
        alturaVentana -= 0.1;
    }
    else if(codepoint == 78){// N
        noche=true;
    }
    else if(codepoint == 110){ // n
        noche=false;
    }
}


void funScroll( GLFWwindow * ventana, double xoffset, double yoffset){
    if(yoffset==1 && valorFovy>=10.0)
        valorFovy-=5;
    if(yoffset==-1 && valorFovy<=90.0)
        valorFovy+=5;
}

static  void funCursorPosition( GLFWwindow * ventana, double xpos, double ypos){

    if(glfwGetMouseButton(ventana,GLFW_MOUSE_BUTTON_LEFT)==GLFW_RELEASE) return;

    float limY = 89.0;
    alphaX = 90.0*(2.0*xpos/(float)w - 1.0);
    alphaY = 90.0*(1.0 - 2.0*ypos/(float)h);
    if(alphaY<-limY) alphaY = -limY;
    if(alphaY> limY) alphaY =  limY;

}




