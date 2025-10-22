#include"sprite.h"


SpriteRenderer::SpriteRenderer(Shader shader)
    :shader(shader)
{
    this->InitRenderData();
}


void SpriteRenderer::InitRenderData()
{
    float vertices[] = {
        // pos      // tex
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };

    glGenVertexArrays(1, &this->VAO);
    glBindVertexArray(this->VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


}

void SpriteRenderer::Render(Texture2D texture, glm::vec2 position, glm::vec2 size, GLfloat rotation, glm::vec3 color)
{
    glm::mat4 model = glm::mat4(1.0f); //Create a model 
    model = glm::translate(model, glm::vec3(position, 0.0f)); // move to a paticular position
    model = glm::translate(model, glm::vec3(0.5 * size.x, 0.5 * size.y, 0.0f)); // change pivot from left corner to centre
    model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f)); // rotate the sprite
    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5 * size.y, 0.0f)); // undo the position of pivot
    model = glm::scale(model, glm::vec3(size, 1.0f));

    this->shader.use();
    this->shader.SetMatrix4("model", model);
    this->shader.SetVector3f("spriteColor", color);

    glActiveTexture(GL_TEXTURE0);
    texture.bind();

    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);


}