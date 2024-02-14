//uniform vec4 color;
uniform sampler2D texture;
varying vec2 varyingTextureCoordinate;
//varying lowp vec4 color;
//out vec4 fragColor;

void main(void)
{
    //gl_FragColor = color;
    gl_FragColor = texture2D(texture, varyingTextureCoordinate);
}
