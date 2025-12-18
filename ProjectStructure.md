```shell
pwn4heap
├── Disclaimer.md                       # Legal Compliance
├── LICENSE
├── ProjectStructure.md
├── pyproject.toml                      # Python dependencies
├── README.md
├── requirements.txt                    # Python dependencies
├── src
│   ├── 2.23                            # Techniques for glibc 2.23
│   │   ├── binary                      # binary files for glibc 2.23
│   │   ├── fast_bin_attack
│   │   ├── fast_bin_attack_bss
│   │   ├── house_of_apple_eight
│   │   ├── house_of_apple_five
│   │   ├── house_of_apple_four
│   │   ├── house_of_apple_one
│   │   ├── house_of_apple_seven
│   │   ├── house_of_apple_six
│   │   ├── house_of_apple_three
│   │   ├── house_of_apple_two
│   │   ├── house_of_banana
│   │   ├── house_of_corrosion
│   │   ├── house_of_einherjar
│   │   ├── house_of_emma
│   │   ├── house_of_emma_again
│   │   ├── house_of_force
│   │   ├── house_of_fun
│   │   ├── house_of_gods
│   │   ├── house_of_gods_again
│   │   ├── house_of_husk
│   │   ├── house_of_husk_again
│   │   ├── house_of_kiwi
│   │   ├── house_of_kiwi_again
│   │   ├── house_of_lore
│   │   ├── house_of_mind_fastbin
│   │   ├── house_of_obstack
│   │   ├── house_of_orange
│   │   ├── house_of_pig
│   │   ├── house_of_pig_again
│   │   ├── house_of_rabbit
│   │   ├── house_of_roman
│   │   ├── house_of_spirit
│   │   ├── house_of_storm
│   │   ├── large_bin_attack
│   │   ├── large_bin_attack_again
│   │   ├── overlapping_chunks
│   │   ├── poison_null_byte
│   │   ├── sysmalloc_int_free
│   │   ├── unsafe_unlink
│   │   ├── unsorted_bin_attack
│   │   ├── unsorted_bin_attack_again
│   │   ├── unsorted_bin_attack_bss
│   │   └── unsorted_bin_leak
│   ├── 2.27                            # Techniques for glibc 2.27
│   │   ├── binary                      # binary files for glibc 2.27
│   │   ├── fast_bin_attack
│   │   ├── fast_bin_attack_bss
│   │   ├── fast_bin_reverse_into_tcache
│   │   ├── fast_bin_reverse_into_tcache_again
│   │   ├── house_of_apple_eight
│   │   ├── house_of_apple_five
│   │   ├── house_of_apple_four
│   │   ├── house_of_apple_one
│   │   ├── house_of_apple_seven
│   │   ├── house_of_apple_six
│   │   ├── house_of_apple_three
│   │   ├── house_of_apple_two
│   │   ├── house_of_atum
│   │   ├── house_of_banana
│   │   ├── house_of_botcake
│   │   ├── house_of_corrosion
│   │   ├── house_of_einherjar
│   │   ├── house_of_emma
│   │   ├── house_of_emma_again
│   │   ├── house_of_force
│   │   ├── house_of_fun
│   │   ├── house_of_husk
│   │   ├── house_of_husk_again
│   │   ├── house_of_kiwi
│   │   ├── house_of_lore
│   │   ├── house_of_lore_again
│   │   ├── house_of_mind_fastbin
│   │   ├── house_of_obstack
│   │   ├── house_of_pig
│   │   ├── house_of_pig_again
│   │   ├── house_of_rabbit
│   │   ├── house_of_roman
│   │   ├── house_of_spirit
│   │   ├── house_of_storm
│   │   ├── house_of_tangerine
│   │   ├── large_bin_attack
│   │   ├── large_bin_attack_again
│   │   ├── overlapping_chunks
│   │   ├── poison_null_byte
│   │   ├── sysmalloc_int_free
│   │   ├── sysmalloc_int_free_again
│   │   ├── tcache_house_of_spirit
│   │   ├── tcache_metadata_poisoning
│   │   ├── tcache_poisoning
│   │   ├── tcache_poisoning_again
│   │   ├── tcache_stashing_unlink_attack
│   │   ├── tcache_stashing_unlink_attack_again
│   │   ├── tcache_stashing_unlink_attack_another
│   │   ├── unsafe_unlink
│   │   ├── unsafe_unlink_again
│   │   ├── unsorted_bin_attack
│   │   ├── unsorted_bin_attack_again
│   │   ├── unsorted_bin_attack_bss
│   │   ├── unsorted_bin_leak
│   │   └── unsorted_bin_leak_again
│   ├── 2.31                            # Techniques for glibc 2.31
│   │   ├── binary                      # binary files for glibc 2.31
│   │   ├── fast_bin_attack
│   │   ├── fast_bin_attack_bss
│   │   ├── fast_bin_reverse_into_tcache
│   │   ├── fast_bin_reverse_into_tcache_again
│   │   ├── house_of_apple_eight
│   │   ├── house_of_apple_five
│   │   ├── house_of_apple_four
│   │   ├── house_of_apple_nine
│   │   ├── house_of_apple_one
│   │   ├── house_of_apple_seven
│   │   ├── house_of_apple_six
│   │   ├── house_of_apple_three
│   │   ├── house_of_apple_two
│   │   ├── house_of_banana
│   │   ├── house_of_botcake
│   │   ├── house_of_corrosion
│   │   ├── house_of_einherjar
│   │   ├── house_of_einherjar_again
│   │   ├── house_of_einherjar_another
│   │   ├── house_of_emma
│   │   ├── house_of_husk
│   │   ├── house_of_husk_again
│   │   ├── house_of_io
│   │   ├── house_of_kiwi
│   │   ├── house_of_lore
│   │   ├── house_of_lore_again
│   │   ├── house_of_mind_fastbin
│   │   ├── house_of_obstack
│   │   ├── house_of_pig
│   │   ├── house_of_spirit
│   │   ├── house_of_tangerine
│   │   ├── large_bin_attack
│   │   ├── large_bin_attack_again
│   │   ├── overlapping_chunks
│   │   ├── poison_null_byte
│   │   ├── sysmalloc_int_free
│   │   ├── sysmalloc_int_free_again
│   │   ├── tcache_house_of_spirit
│   │   ├── tcache_metadata_poisoning
│   │   ├── tcache_poisoning
│   │   ├── tcache_poisoning_again
│   │   ├── tcache_stashing_unlink_attack
│   │   ├── tcache_stashing_unlink_attack_again
│   │   ├── tcache_stashing_unlink_attack_another
│   │   ├── unsafe_unlink
│   │   ├── unsafe_unlink_again
│   │   ├── unsorted_bin_leak
│   │   └── unsorted_bin_leak_again
│   ├── 2.35                            # Techniques for glibc 2.35
│   │   ├── binary                      # binary files for glibc 2.35
│   │   ├── fast_bin_attack_bss
│   │   ├── fast_bin_reverse_into_tcache
│   │   ├── fast_bin_reverse_into_tcache_again
│   │   ├── house_of_apple_eight
│   │   ├── house_of_apple_five
│   │   ├── house_of_apple_four
│   │   ├── house_of_apple_nine
│   │   ├── house_of_apple_one
│   │   ├── house_of_apple_seven
│   │   ├── house_of_apple_six
│   │   ├── house_of_apple_three
│   │   ├── house_of_apple_two
│   │   ├── house_of_banana
│   │   ├── house_of_botcake
│   │   ├── house_of_corrosion
│   │   ├── house_of_einherjar
│   │   ├── house_of_einherjar_again
│   │   ├── house_of_einherjar_another
│   │   ├── house_of_emma_four
│   │   ├── house_of_emma_one
│   │   ├── house_of_emma_three
│   │   ├── house_of_emma_two
│   │   ├── house_of_husk
│   │   ├── house_of_husk_again
│   │   ├── house_of_io
│   │   ├── house_of_kiwi
│   │   ├── house_of_lore
│   │   ├── house_of_mind_fastbin
│   │   ├── house_of_obstack
│   │   ├── house_of_spirit
│   │   ├── large_bin_attack
│   │   ├── large_bin_attack_again
│   │   ├── overlapping_chunks
│   │   ├── poison_null_byte
│   │   ├── sysmalloc_int_free
│   │   ├── sysmalloc_int_free_again
│   │   ├── tcache_house_of_spirit
│   │   ├── tcache_metadata_poisoning
│   │   ├── tcache_poisoning
│   │   ├── tcache_poisoning_again
│   │   ├── tcache_stashing_unlink+_attack
│   │   ├── tcache_stashing_unlink_attack
│   │   ├── unsafe_unlink
│   │   ├── unsafe_unlink_again
│   │   ├── unsorted_bin_leak
│   │   └── unsorted_bin_leak_again
│   └── 2.39                            # Techniques for glibc 2.39
│       ├── binary                      # binary files for glibc 2.39
│       ├── fast_bin_attack_bss
│       ├── fast_bin_reverse_into_tcache
│       ├── fast_bin_reverse_into_tcache_again
│       ├── house_of_apple_eight
│       ├── house_of_apple_five
│       ├── house_of_apple_four
│       ├── house_of_apple_nine
│       ├── house_of_apple_one
│       ├── house_of_apple_seven
│       ├── house_of_apple_six
│       ├── house_of_apple_three
│       ├── house_of_apple_two
│       ├── house_of_banana
│       ├── house_of_botcake
│       ├── house_of_einherjar
│       ├── house_of_einherjar_again
│       ├── house_of_einherjar_another
│       ├── house_of_emma_four
│       ├── house_of_emma_one
│       ├── house_of_emma_three
│       ├── house_of_emma_two
│       ├── house_of_husk
│       ├── house_of_husk_again
│       ├── house_of_io
│       ├── house_of_lore
│       ├── house_of_mind_fastbin
│       ├── house_of_snake
│       ├── house_of_spirit
│       ├── large_bin_attack
│       ├── large_bin_attack_again
│       ├── overlapping_chunks
│       ├── poison_null_byte
│       ├── sysmalloc_int_free
│       ├── sysmalloc_int_free_again
│       ├── tcache_house_of_spirit
│       ├── tcache_metadata_poisoning
│       ├── tcache_poisoning
│       ├── tcache_poisoning_again
│       ├── tcache_stashing_unlink+_attack
│       ├── tcache_stashing_unlink_attack
│       ├── unsafe_unlink
│       ├── unsafe_unlink_again
│       ├── unsorted_bin_leak
│       └── unsorted_bin_leak_again
└── uv.lock
```
