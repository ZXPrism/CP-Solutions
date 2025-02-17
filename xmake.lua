set_project("CP-Solutions")

add_rules("mode.debug", "mode.release")

target("default")
    set_languages("cxx23")
    set_kind("binary")
    set_warnings("all", "error")

    add_files("**.cpp")
    add_includedirs(".")
target_end()
