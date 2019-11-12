include(FetchContent)

function(INSTALL_DEP SLUG REPO TAG OUTPUT FILES_COPY)
    FetchContent_Declare(
        ${SLUG}
        GIT_REPOSITORY ${REPO}
        GIT_TAG ${TAG}
    )
    FetchContent_GetProperties(${SLUG})

    if(NOT ${${SLUG}_POPULATED})

        message("Install ${SLUG}")
        FetchContent_Populate(${SLUG})

        set(DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/${OUTPUT})

        foreach(FILE_COPY ${FILES_COPY})
            file(COPY
                    ${${SLUG}_SOURCE_DIR}/${FILE_COPY}
                    DESTINATION ${DESTINATION}
            )
        endforeach(FILE_COPY)
    endif()

endfunction(INSTALL_DEP)