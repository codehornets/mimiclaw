#pragma once

#include "esp_err.h"
#include <stddef.h>

/**
 * Initialize the LLM proxy. Reads API key and model from NVS.
 */
esp_err_t llm_proxy_init(void);

/**
 * Send a chat completion request to Anthropic Messages API (streaming).
 *
 * @param system_prompt  System prompt string
 * @param messages_json  JSON array of messages: [{"role":"user","content":"..."},...]
 * @param response_buf   Output buffer for the complete response text
 * @param buf_size       Size of response_buf
 * @return ESP_OK on success
 */
esp_err_t llm_chat(const char *system_prompt, const char *messages_json,
                   char *response_buf, size_t buf_size);

/**
 * Save the Anthropic API key to NVS.
 */
esp_err_t llm_set_api_key(const char *api_key);

/**
 * Save the model identifier to NVS.
 */
esp_err_t llm_set_model(const char *model);
