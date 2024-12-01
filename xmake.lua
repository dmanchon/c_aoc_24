add_rules("mode.debug", "mode.release")

target("day1")
    set_kind("binary")
    add_files("src/day1/main.c")
